// CMessenger.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFC Albago_Alba.h"
#include "CMessenger.h"
#include "afxdialogex.h"
#include "CMySocket2.h"


// CMessenger 대화 상자

IMPLEMENT_DYNAMIC(CMessenger, CDialog)

CMessenger::CMessenger(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MESSENGER, pParent)
	, m_iType(0)
	, m_strName(_T(""))
	, m_strMessage(_T(""))
{

}

CMessenger::~CMessenger()
{
}

void CMessenger::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, 1015, m_iType);
	DDX_Text(pDX, 1008, m_strName);
	DDX_Text(pDX, IDC_EMSG, m_strMessage);
	DDX_Control(pDX, IDC_LIST, m_mesgbox);
}


BEGIN_MESSAGE_MAP(CMessenger, CDialog)
	ON_BN_CLICKED(1015, &CMessenger::OnRType)
	ON_BN_CLICKED(1016, &CMessenger::OnRType)
	ON_BN_CLICKED(1010, &CMessenger::OnBnClickedBlisten)
	ON_BN_CLICKED(1011, &CMessenger::OnBnClickedBconnect)
	ON_BN_CLICKED(IDC_BSEND, &CMessenger::OnBnClickedBsend)
END_MESSAGE_MAP()


// CMessenger 메시지 처리기


BOOL CMessenger::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_strName = "localhost"; // 자기자신 PC로 접속(Editor Control)
	m_iType = 0; // radio button
	UpdateData(FALSE);
	m_Csocket.SetParent(this);
	m_Ssocket.SetParent(this);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CMessenger::OnAccept()
{
	m_Ssocket.Accept(m_Csocket);
	GetDlgItem(1011)->EnableWindow(FALSE);
	GetDlgItem(1010)->EnableWindow(FALSE);
}
void CMessenger::OnConnect()
{
	GetDlgItem(1011)->EnableWindow(FALSE);
	GetDlgItem(1010)->EnableWindow(FALSE);
}
void CMessenger::OnClose()
{
	m_Csocket.Close();
	if (m_iType == 0)
	{
		GetDlgItem(1011)->EnableWindow(FALSE);
		GetDlgItem(1010)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(1011)->EnableWindow(TRUE);
		GetDlgItem(1010)->EnableWindow(FALSE);
	}
}
void CMessenger::OnReceive()
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
		m_mesgbox.AddString(LPCWSTR(pBuf));
		UpdateData(FALSE);
	}
}
void CMessenger::OnSend() { }

void CMessenger::OnRType()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (m_iType == 0) {
		GetDlgItem(1011)->EnableWindow(FALSE);
		GetDlgItem(1010)->EnableWindow(TRUE);
	}
	else {
		GetDlgItem(1011)->EnableWindow(TRUE);
		GetDlgItem(1010)->EnableWindow(FALSE);
	}
}


void CMessenger::OnBnClickedBlisten()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(1011)->EnableWindow(FALSE);
	GetDlgItem(1010)->EnableWindow(FALSE);
	m_Ssocket.Create(4000);
	m_Ssocket.Listen();
}


void CMessenger::OnBnClickedBconnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(1011)->EnableWindow(FALSE);
	GetDlgItem(1010)->EnableWindow(FALSE);
	UpdateData(TRUE);
	m_Csocket.Create();
	m_Csocket.Connect(m_strName, 4000);
}


void CMessenger::OnBnClickedBsend()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int iSent;
	int iLen;
	UpdateData(TRUE);
	if (m_strMessage != "")
	{
		iLen = m_strMessage.GetLength();
		iSent = m_Csocket.Send(LPCTSTR(m_strMessage), sizeof(TCHAR)*(iLen + 1));
		if (iSent == SOCKET_ERROR) {
			MessageBox(_T("error"));
		}
		else
		{
			m_mesgbox.AddString(_T("당신 : ")+m_strMessage);
			UpdateData(FALSE);
		}
	}
}
