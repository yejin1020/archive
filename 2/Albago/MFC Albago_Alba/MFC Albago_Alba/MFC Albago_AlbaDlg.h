
// MFC Albago_AlbaDlg.h: 헤더 파일
//
#include "CMySocket.h"
#pragma once


// CMFCAlbagoAlbaDlg 대화 상자
class CMFCAlbagoAlbaDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCAlbagoAlbaDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCALBAGO_ALBA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtAdd();
//	CListCtrl ctrl_listpay;
	afx_msg void OnBnClickedButton3();
	CListBox m_Lpay;
	int m_iType;
	CString m_strName;
	afx_msg void OnRType();
	CMySocket m_Ssocket, m_Csocket;
	void OnAccept();
	void OnConnect();
	void OnClose();
	void OnReceive();
	void OnSend();
	afx_msg void OnBnClickedBlisten();
	afx_msg void OnBnClickedBconnect();
	int m_iPaintType;
	CString enpay;
	afx_msg void OnBnClickedMessage();
	afx_msg void OnBnClickedButtShadd();
};
