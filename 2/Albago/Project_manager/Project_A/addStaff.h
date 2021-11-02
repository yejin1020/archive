#pragma once


// addStaff 대화 상자

class addStaff : public CDialog
{
	DECLARE_DYNAMIC(addStaff)

public:
	addStaff(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~addStaff();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_STAFF };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_staffname;
	CString m_staffage;
	CString m_stafftime;
	CString m_staffaccount;
	CString m_staffphonenum;
	afx_msg void OnPaint();
};
