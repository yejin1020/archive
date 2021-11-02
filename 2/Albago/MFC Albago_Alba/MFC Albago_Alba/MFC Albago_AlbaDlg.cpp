
// MFC Albago_AlbaDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFC Albago_Alba.h"
#include "MFC Albago_AlbaDlg.h"
#include "afxdialogex.h"
#include "CCALPAY.h"
#include "CMySocket.h"
#include "CMessenger.h"
#include "CCalendar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCAlbagoAlbaDlg 대화 상자



CMFCAlbagoAlbaDlg::CMFCAlbagoAlbaDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCALBAGO_ALBA_DIALOG, pParent)
	, m_iType(0)
	, m_strName(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCAlbagoAlbaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_LISTPAY, ctrl_listpay);
	DDX_Control(pDX, IDC_LISTMONEY, m_Lpay);
	DDX_Radio(pDX, IDC_RSERVER, m_iType);
	DDX_Text(pDX, IDC_ESERVNAME, m_strName);
}

BEGIN_MESSAGE_MAP(CMFCAlbagoAlbaDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_ADD, &CMFCAlbagoAlbaDlg::OnBnClickedButtAdd)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCAlbagoAlbaDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_RSERVER, &CMFCAlbagoAlbaDlg::OnRType)
	ON_BN_CLICKED(IDC_RCLIENT, &CMFCAlbagoAlbaDlg::OnRType)
	ON_BN_CLICKED(IDC_BLISTEN, &CMFCAlbagoAlbaDlg::OnBnClickedBlisten)
	ON_BN_CLICKED(IDC_BCONNECT, &CMFCAlbagoAlbaDlg::OnBnClickedBconnect)
	ON_BN_CLICKED(IDC_Message, &CMFCAlbagoAlbaDlg::OnBnClickedMessage)
	ON_BN_CLICKED(IDC_BUTT_SHADD, &CMFCAlbagoAlbaDlg::OnBnClickedButtShadd)
END_MESSAGE_MAP()


// CMFCAlbagoAlbaDlg 메시지 처리기

BOOL CMFCAlbagoAlbaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_strName = "localhost"; // 자기자신 PC로 접속(Editor Control)
	m_iType = 0; // radio button
	UpdateData(FALSE);
	m_Csocket.SetParent(this);
	m_Ssocket.SetParent(this);
	m_iPaintType = 0;
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCAlbagoAlbaDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCAlbagoAlbaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		CFont font;
		font.CreateFontW(40, 0, 0, 0, 0, 0, 0, 0, 0, 0, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, _T("배달의민족 주아"));
		GetDlgItem(IDC_STATIC)->SetFont(&font);
		GetDlgItem(IDC_STATIC_PAY)->SetFont(&font);
		font.CreateFontW(50, 0, 0, 0, 0, 0, 0, 0, 0, 0, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, _T("배달의민족 주아"));
		GetDlgItem(IDC_STATIC_alba)->SetFont(&font);
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCAlbagoAlbaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCAlbagoAlbaDlg::OnBnClickedButtAdd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CCALPAY cp;
	cp.DoModal();
	
	static int line = 0;
	//CString str;
	//enpay.Format(_T("신청 금액 : %g원   지급 상태 : "), cp.m_DTMoney);

	// 출근 날짜
	CString stringstday = cp.startdate.Format(_T("%Y 년 %m 월 %d 일"));

	enpay.Format(_T("근무 요일 : %s   신청 금액 : %g원   지급 상태 : 미지급"), stringstday, cp.m_DTMoney);

	m_Lpay.AddString(enpay);
	
}

void CMFCAlbagoAlbaDlg::OnBnClickedButton3()//급여신청
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int iSent;
	int iLen;
	UpdateData(TRUE);
	if (enpay != "")
	{
		iLen = enpay.GetLength();
		iSent = m_Csocket.Send(LPCTSTR(enpay), sizeof(TCHAR)*(iLen + 1));
		if (iSent == SOCKET_ERROR) {
			MessageBox(_T("error"));
		}
		else
		{
			//m_Lpay.AddString(enpay);
			//UpdateData(FALSE);
			CString str;
			str.Format(_T("신청이 완료되었습니다."));
			AfxMessageBox(str);
		}
	}
}

void CMFCAlbagoAlbaDlg::OnRType()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (m_iType == 0) {
		GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
		GetDlgItem(IDC_BLISTEN)->EnableWindow(TRUE);
	}
	else {
		GetDlgItem(IDC_BCONNECT)->EnableWindow(TRUE);
		GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	}
}
void CMFCAlbagoAlbaDlg::OnAccept()
{
	m_Ssocket.Accept(m_Csocket);
	GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
}
void CMFCAlbagoAlbaDlg::OnConnect()
{
	GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
}
void CMFCAlbagoAlbaDlg::OnClose()
{
	m_Csocket.Close();
	if (m_iType == 0)
	{
		GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
		GetDlgItem(IDC_BLISTEN)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_BCONNECT)->EnableWindow(TRUE);
		GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	}
}
void CMFCAlbagoAlbaDlg::OnSend(){}
void CMFCAlbagoAlbaDlg::OnReceive()
{
	char *pBuf = new char[1025];
	int iBufSize = 1024;
	int iRcvd;
	iRcvd = m_Csocket.Receive(pBuf, iBufSize);
	if (iRcvd == SOCKET_ERROR)
	{
	}
	else {
		pBuf[iRcvd] = NULL;
		m_Lpay.AddString(LPCWSTR(pBuf));
		UpdateData(FALSE);
	}
}
void CMFCAlbagoAlbaDlg::OnBnClickedBlisten()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	m_Ssocket.Create(4000);
	m_Ssocket.Listen();
}
void CMFCAlbagoAlbaDlg::OnBnClickedBconnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN)->EnableWindow(FALSE);
	UpdateData(TRUE);
	m_Csocket.Create();
	m_Csocket.Connect(m_strName, 4000);
}


void CMFCAlbagoAlbaDlg::OnBnClickedMessage()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMessenger cm;
	cm.DoModal();
}


void CMFCAlbagoAlbaDlg::OnBnClickedButtShadd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CCalendar cd;
	//cd.DoModal();
}
