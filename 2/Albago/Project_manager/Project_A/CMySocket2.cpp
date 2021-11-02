// CMySocket2.cpp: 구현 파일
//

#include "stdafx.h"
#include "Project_A.h"
#include "CMySocket2.h"
#include "Project_ADlg.h"


// CMySocket2

CMySocket2::CMySocket2()
{
}

CMySocket2::~CMySocket2()
{
}


// CMySocket2 멤버 함수
void CMySocket2::SetParent(CDialog *pWnd)
{
	m_pWnd = pWnd;
}

void CMySocket2::OnAccept(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0)
		((CProjectADlg*)m_pWnd)->OnAccept();
	//::OnAccept(nErrorCode);
}


void CMySocket2::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0)
		((CProjectADlg*)m_pWnd)->OnClose();
	//CAsyncSocket::OnClose(nErrorCode);
}


void CMySocket2::OnConnect(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0)
		((CProjectADlg*)m_pWnd)->OnConnect();
	//CAsyncSocket::OnConnect(nErrorCode);
}


void CMySocket2::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0)
		((CProjectADlg*)m_pWnd)->OnReceive();
	//CAsyncSocket::OnReceive(nErrorCode);
}


void CMySocket2::OnSend(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0)
		((CProjectADlg*)m_pWnd)->OnSend();
	//CAsyncSocket::OnSend(nErrorCode);
}
