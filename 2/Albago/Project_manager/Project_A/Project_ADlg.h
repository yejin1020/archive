
// Project_ADlg.h: 헤더 파일
//
#include "addStaff.h"
#include "CCalendar.h"
#include "CMySocket.h"
#include "CMySocket2.h"
#pragma once


// CProjectADlg 대화 상자
class CProjectADlg : public CDialogEx
{
// 생성입니다.
public:
	CProjectADlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROJECT_A_DIALOG };
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
	CListBox m_ctlList;
	afx_msg void OnBnClickedButtAddStaff();
	CListBox m_staffinfo;
	CListCtrl m_list;
	void dataOpen(CString sFilePath, CListCtrl* pLC);
	int getFindCharCount(CString sFileContent, CString sFindString);
	void LoadLine();
	void staffinfo_write();
	afx_msg void OnBnClickedButtScheduleAdd();
	afx_msg void OnBnClickedButtMessage();
//	CListBox m_messageBox;
	void getMessage();
	CMySocket2 m_Ssocket, m_Csocket;
//	int m_iType;
	void OnAccept();
	void OnConnect();
	void OnClose();
	void OnReceive();
	void OnSend();
	CString m_strName;
	afx_msg void OnRType();
	afx_msg void OnBnClickedBlisten2();
	afx_msg void OnBnClickedBconnect2();
	CListBox m_paylist;
	afx_msg void OnBnClickedButtPaySave();
	int m_iType2;
	afx_msg void OnBnClickedButtDelStaff();
};
