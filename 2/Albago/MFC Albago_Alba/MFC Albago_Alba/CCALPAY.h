#pragma once


// CCALPAY 대화 상자

class CCALPAY : public CDialog
{
	DECLARE_DYNAMIC(CCALPAY)

public:
	CCALPAY(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CCALPAY();
	COleDateTime  m_time;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALPAY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CDateTimeCtrl m_endday;
	CDateTimeCtrl m_endtime;
	CDateTimeCtrl m_restday;
	CDateTimeCtrl m_resttime;
	CDateTimeCtrl m_startday;
	CDateTimeCtrl m_starttime;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();


	void caltime();
	int m_HMoney;
	//afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedResultm();
	double m_DTMoney;
	CTime startdate;
	static UINT CreateThread(void * IParam);
	afx_msg void OnPaint();
};
