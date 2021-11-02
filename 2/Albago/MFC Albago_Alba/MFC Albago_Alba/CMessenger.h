#pragma once

#include "MFC Albago_AlbaDlg.h"
#include "CMySocket2.h"

// CMessenger 대화 상자

class CMessenger : public CDialog
{
	DECLARE_DYNAMIC(CMessenger)

public:
	CMessenger(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMessenger();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MESSENGER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CMySocket2 m_Ssocket, m_Csocket;
	void OnAccept();
	void OnConnect();
	void OnClose();
	void OnReceive();
	void OnSend();
	virtual BOOL OnInitDialog();
	int m_iType;
	CString m_strName;
	afx_msg void OnRType();
	afx_msg void OnBnClickedBlisten();
	afx_msg void OnBnClickedBconnect();
	afx_msg void OnBnClickedBsend();
	CString m_strMessage;
	CListBox m_mesgbox;
};
