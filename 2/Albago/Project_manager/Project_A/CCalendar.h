#pragma once
#include "Resource.h"

// CCalendar 대화 상자

class AFX_EXT_CLASS CCalendar : public CDialog
{
	DECLARE_DYNAMIC(CCalendar)

public:
	CCalendar(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CCalendar();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	void OnPaint();
	CListCtrl m_list;
	afx_msg void OnBnClickedButtAdd();
//	COleDateTime m_calendar;
	CString m_date;
	CString m_memo;
	CMonthCalCtrl m_calendar;
	afx_msg void OnSelchangeMonthcalendar1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtDel();
	//void calendar_write();
	void getMemo();
};
