
// Project_ADlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Project_A.h"
#include "Project_ADlg.h"
#include "afxdialogex.h"
#include "addStaff.h"
#include "CCalendar.h"
#include "CMessenger.h"
#include "CMySocket2.h"


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


// CProjectADlg 대화 상자



CProjectADlg::CProjectADlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PROJECT_A_DIALOG, pParent)
	, m_strName(_T(""))
	, m_iType2(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProjectADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_ESERVERNAME, m_strName);
	DDX_Control(pDX, IDC_LIST_PAY, m_paylist);
	DDX_Radio(pDX, IDC_RSERVER, m_iType2);
}

BEGIN_MESSAGE_MAP(CProjectADlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_ADD_STAFF, &CProjectADlg::OnBnClickedButtAddStaff)
	ON_BN_CLICKED(IDC_BUTT_SCHEDULE_ADD, &CProjectADlg::OnBnClickedButtScheduleAdd)
	ON_BN_CLICKED(IDC_BUTT_MESSAGE, &CProjectADlg::OnBnClickedButtMessage)
	ON_BN_CLICKED(IDC_RSERVER, &CProjectADlg::OnRType)
	ON_BN_CLICKED(IDC_RCLIENT, &CProjectADlg::OnRType)
	ON_BN_CLICKED(IDC_BLISTEN2, &CProjectADlg::OnBnClickedBlisten2)
	ON_BN_CLICKED(IDC_BCONNECT2, &CProjectADlg::OnBnClickedBconnect2)
	ON_BN_CLICKED(IDC_BUTT_PAY_SAVE, &CProjectADlg::OnBnClickedButtPaySave)
	ON_BN_CLICKED(IDC_BUTT_DEL_STAFF, &CProjectADlg::OnBnClickedButtDelStaff)
END_MESSAGE_MAP()


// CProjectADlg 메시지 처리기

BOOL CProjectADlg::OnInitDialog()
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
	if (!AfxSocketInit())
	{
		AfxMessageBox(_T("Windows 소켓 초기화에 실패하였습니다."));
		return FALSE;
	}
	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_strName = "localhost"; // 자기자신 PC로 접속(Editor Control)
	m_iType2 = 0; // radio button
	UpdateData(FALSE);
	m_Csocket.SetParent(this);
	m_Ssocket.SetParent(this);
	// 리스트 컨트롤에서 보여질 열의 종류를 미리 초기화.
	m_list.DeleteAllItems();
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES);

	for (int i = 0; i < m_list.GetHeaderCtrl()->GetItemCount(); i++)
		m_list.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);

	m_list.InsertColumn(0, _T("Name"), LVCFMT_CENTER, 80,-1);
	m_list.InsertColumn(1, _T("Age"), LVCFMT_CENTER, 60, -1);
	m_list.InsertColumn(2, _T("Time"), LVCFMT_CENTER, 100, -1);
	m_list.InsertColumn(3, _T("Account"), LVCFMT_CENTER, 185, -1);
	m_list.InsertColumn(4, _T("Phone number"), LVCFMT_CENTER, 180, -1);


	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 텍스트파일이 비어있지 않은 경우 저장된 데이터를 불러와서 컨트롤리스트에 뿌린다.
	LoadLine();
	

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CProjectADlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CProjectADlg::OnPaint()
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
		GetDlgItem(IDC_STATIC_MONEY)->SetFont(&font); 
		GetDlgItem(IDC_STATIC_MESSAGE)->SetFont(&font);
		GetDlgItem(IDC_STATIC_INFO)->SetFont(&font);
		font.CreateFontW(50, 0, 0, 0, 0, 0, 0, 0, 0, 0, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, _T("배달의민족 주아"));
		GetDlgItem(IDC_STATIC_alba)->SetFont(&font);
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CProjectADlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CProjectADlg::OnAccept()
{
	m_Ssocket.Accept(m_Csocket);
	GetDlgItem(IDC_BCONNECT2)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN2)->EnableWindow(FALSE);
}
void CProjectADlg::OnConnect()
{
	GetDlgItem(IDC_BCONNECT2)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN2)->EnableWindow(FALSE);
	
}
void CProjectADlg::OnClose()
{
	m_Csocket.Close();
	if (m_iType2 == 0)
	{
		GetDlgItem(IDC_BCONNECT2)->EnableWindow(FALSE);
		GetDlgItem(IDC_BLISTEN2)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_BCONNECT2)->EnableWindow(TRUE);
		GetDlgItem(IDC_BLISTEN2)->EnableWindow(FALSE);
	}
}
void CProjectADlg::OnSend()
{

}
void CProjectADlg::OnReceive()
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
		m_paylist.AddString(LPCWSTR(pBuf));
		UpdateData(FALSE);
	}
}

// 직원 정보를 입력.

void CProjectADlg::OnBnClickedButtAddStaff()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	addStaff AddInfo;
	static int line = 0;

	// 추가 버튼을 누르면 직원 정보를 입력하는 창이 뜬다
	//새로 띄워진 창에서 확인 버튼을 누르면
	// 옆에 있는 리스트 컨트롤 박스에 입력된 값이 열에 맞게 들어간다.
	if (AddInfo.DoModal() == IDOK)
	{
		m_list.InsertItem(line, AddInfo.m_staffname);
		m_list.SetItem(line, 1, LVIF_TEXT, AddInfo.m_staffage, 0, 0, 0, NULL);
		m_list.SetItem(line, 2, LVIF_TEXT, AddInfo.m_stafftime, 0, 0, 0, NULL);
		m_list.SetItem(line, 3, LVIF_TEXT, AddInfo.m_staffaccount, 0, 0, 0, NULL);
		m_list.SetItem(line, 4, LVIF_TEXT, AddInfo.m_staffphonenum, 0, 0, 0, NULL);
		UpdateData(FALSE);
		line++; // 한 번 실행 될때마라 한 행에 추가된다.

		staffinfo_write();
		
	}
	
}


// 파일에 저장된 문장을 리스트에 뿌린다.
void CProjectADlg::LoadLine() {

	
	CStdioFile src_file;
	src_file.Open(_T("STAFF_INFO.txt"), CFile::modeRead);

	CString  str = _T("");
	CString  str0 = _T("");
	CString  str1 = _T("");
	CString  str2 = _T("");
	CString  str3 = _T("");
	CString  str4 = _T("");
	CString display_str;
	int txtline = 0;

	//src_file.ReadString(str) 파일의 전체 한문장을 읽어오게된다 \r로 구분된 한 문장을 읽어올 수 있어야한다.
	while (src_file.ReadString(str)) // 한줄씩 파일에서 읽어온다. 더이상 읽을 문장이 없으면 반복을 종료한다.
	{
		
		AfxExtractSubString(str0, str, 0, ' ');
		AfxExtractSubString(str1, str, 1, ' ');
		AfxExtractSubString(str2, str, 2, ' ');
		AfxExtractSubString(str3, str, 3, ' ');
		AfxExtractSubString(str4, str, 4, ' ');

		m_list.InsertItem(txtline, str0);
		m_list.SetItem(txtline, 1, LVIF_TEXT, str1, 0, 0, 0, NULL);
		m_list.SetItem(txtline, 2, LVIF_TEXT, str2, 0, 0, 0, NULL);
		m_list.SetItem(txtline, 3, LVIF_TEXT, str3, 0, 0, 0, NULL);
		m_list.SetItem(txtline, 4, LVIF_TEXT, str4, 0, 0, 0, NULL);

		txtline++;
		// 파일에서 읽어온 문장을 출력한다.
		//display_str += str;
	   // AfxMessageBox(str);
	}
	return ;
}


// 입력된 정보를 텍스트 파일에 저장하는 메서드
void CProjectADlg::staffinfo_write()
{
	// TODO: 여기에 구현 코드 추가.

	CStdioFile file; // 파일 열기

	file.Open(_T("STAFF_INFO.txt"), CFile::modeWrite);

	CHeaderCtrl* pHeader = (CHeaderCtrl*)m_list.GetHeaderCtrl(); // 헤더컨트롤 얻어오기

	int nRow = m_list.GetItemCount(); // Row 갯수

	int nCol = pHeader->GetItemCount(); // Col 갯수

	CString text;

	for (int i = 0; i < nRow; i++)
	{
		text = "";

		for (int j = 0; j < nCol; j++)
		{
			text += m_list.GetItemText(i, j); // 아이템 텍스트 가져오기
			text += " ";
		}
		file.WriteString(text + "\n"); // 파일에 쓰기
	}

	file.Close();

}

void CProjectADlg::OnBnClickedButtScheduleAdd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CCalendar cd;
	cd.DoModal();
}

void CProjectADlg::OnBnClickedButtMessage()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMessenger cm;
	cm.DoModal();
}


void CProjectADlg::OnRType()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (m_iType2 == 0) {
		GetDlgItem(IDC_BCONNECT2)->EnableWindow(FALSE);
		GetDlgItem(IDC_BLISTEN2)->EnableWindow(TRUE);
	}
	else {
		GetDlgItem(IDC_BCONNECT2)->EnableWindow(TRUE);
		GetDlgItem(IDC_BLISTEN2)->EnableWindow(FALSE);
	}
}

void CProjectADlg::OnBnClickedBlisten2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_BCONNECT2)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN2)->EnableWindow(FALSE);
	m_Ssocket.Create(4000);
	m_Ssocket.Listen();
}


void CProjectADlg::OnBnClickedBconnect2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_BCONNECT2)->EnableWindow(FALSE);
	GetDlgItem(IDC_BLISTEN2)->EnableWindow(FALSE);
	UpdateData(TRUE);
	m_Csocket.Create();
	m_Csocket.Connect(m_strName, 4000);
}


void CProjectADlg::OnBnClickedButtPaySave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int index = m_paylist.GetCurSel();
	CString str;
	str.Format(_T("지급완료"));
	CString ss;
	m_paylist.GetText(index, ss);
	if (IDOK == MessageBox(_T("지급 완료로 변경하시겠습니까?"))) {

		m_paylist.DeleteString(index);
		m_paylist.AddString(str);
		ss = ss + _T("완료");
	}

	int iSent;
	int iLen;
	UpdateData(TRUE);
	if (ss != "")
	{
		iLen = ss.GetLength();
		iSent = m_Csocket.Send(LPCTSTR(ss), sizeof(TCHAR)*(iLen + 1));
		if (iSent == SOCKET_ERROR) {
			MessageBox(_T("error"));
		}
	}
}

void CProjectADlg::OnBnClickedButtDelStaff()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	int nItem = m_list.GetNextSelectedItem(pos);
	// 선택행 열의 위치를 가지고 온다.

	m_list.DeleteItem(nItem); // 선택 행 삭제

}
