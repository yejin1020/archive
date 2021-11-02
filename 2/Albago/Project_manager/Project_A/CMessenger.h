#pragma once
#include "Project_ADlg.h"
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
	CMySocket m_Ssocket, m_Csocket;
	int m_iType;
	int m_iPaintType;

	CString m_strName;
	afx_msg void OnRType();
	void OnAccept();
	void OnConnect();
	void OnClose();
	void OnReceive();
	void OnSend();

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBlisten();
	afx_msg void OnBnClickedBconnect();
	CListBox m_message;
	CString m_strMessage;
	afx_msg void OnBnClickedBsend();

};
