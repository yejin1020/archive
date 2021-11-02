// CCALPAY.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFC Albago_Alba.h"
#include "CCALPAY.h"
#include "afxdialogex.h"


// CCALPAY 대화 상자

IMPLEMENT_DYNAMIC(CCALPAY, CDialog)

CCALPAY::CCALPAY(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CALPAY, pParent)
	, m_DTMoney(0)
	, m_HMoney(0)
	
{

}

CCALPAY::~CCALPAY()
{
}

void CCALPAY::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_END_DAY, m_endday);
	DDX_Control(pDX, IDC_END_TIME, m_endtime);
	DDX_Control(pDX, IDC_REST_DAY, m_restday);
	DDX_Control(pDX, IDC_REST_TIME, m_resttime);
	DDX_Control(pDX, IDC_START_DAY, m_startday);
	DDX_Control(pDX, IDC_START_TIME, m_starttime);
	DDX_Text(pDX, IDC_HourM, m_HMoney);
	DDX_Text(pDX, IDC_DayTotalM, m_DTMoney);
}


BEGIN_MESSAGE_MAP(CCALPAY, CDialog)
	ON_BN_CLICKED(IDOK, &CCALPAY::OnBnClickedOk)
//	ON_BN_CLICKED(IDC_BUTTON1, &CCALPAY::OnBnClickedButton1)
   ON_BN_CLICKED(IDC_ResultM, &CCALPAY::OnBnClickedResultm)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CCALPAY 메시지 처리기


BOOL CCALPAY::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	COleDateTime timeNow = COleDateTime::GetCurrentTime();
	//현재 시간을 가져온다.

	m_starttime.SetFormat(_T("HH시 mm분 ss초"));
	m_endtime.SetFormat(_T("HH시 mm분 ss초"));
	m_resttime.SetFormat(_T("HH시 mm분 ss초"));
	//표시 방식 세팅

	m_time = COleDateTime(timeNow.GetYear(), timeNow.GetMonth(), timeNow.GetDay(), 14, 59, 00);
	VERIFY(m_starttime.SetTime(m_time));
	VERIFY(m_endtime.SetTime(m_time));
	VERIFY(m_resttime.SetTime(m_time));
	//시간을 입력 한다


	// Date Time Picker 에서 값을 가져오기

	VERIFY(m_starttime.GetTime(m_time));
	VERIFY(m_endtime.GetTime(m_time));
	VERIFY(m_resttime.GetTime(m_time));

	//시간 값을 컨트롤에서 가져온다.


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

//하루동안 일한 시간 구한다
void CCALPAY::caltime() {


	UpdateData(TRUE);
	SYSTEMTIME st, st1, st2, st3, st4, st5;

	// SYSTEMTIME 구조체에 시간 정보 저장됨
	m_starttime.GetTime(&st); // 출근 시간
	// SYSTEMTIME을 CTime형식으로 변환
	CTime t(st);

	m_endtime.GetTime(&st1); // 퇴근 시간
	CTime t1(st1);

	m_startday.GetTime(&st2); // 출근 날짜
	CTime t2(st2);

	m_endday.GetTime(&st3); // 퇴근 날짜
	CTime t3(st3);

	m_restday.GetTime(&st4); // 쉬는 날짜
	CTime t7(st4);

	m_resttime.GetTime(&st5); // 쉬는 시간
	CTime t8(st5);

	CTimeSpan ts1(0, t8.GetHour(), t8.GetMinute(), t8.GetSecond()); //쉬는 시간 시, 분,초 로 받아온다

	CTime t4(t2.GetYear(), t2.GetMonth(), t2.GetDay(), t.GetHour(), t.GetMinute(), t.GetSecond()); // 출근 시, 분,초 로 받아온다
	CTime t5(t3.GetYear(), t3.GetMonth(), t3.GetDay(), t1.GetHour(), t1.GetMinute(), t1.GetSecond()); // 퇴근 시, 분,초 로 받아온다

	CTimeSpan t6 = t5 - t4; //  퇴근 시간 - 출근 시간
	CTimeSpan tresult = t6 - ts1; // ( 퇴근 시간 - 출근 시간) - 쉬는 시간

	//CString str = tresult.Format(_T("%D: %H : %M : %S")); // 날, 시, 분, 초로 형식 지정
	//MessageBox(str); // 시간 결과 값 메세지 박스로 창띄운다

	//CTimeSpan t11 =  - t9;
	//CString str2 = t11.Format(_T("%D : %H : %M : %S"));

	m_DTMoney = ( tresult.GetHours() * m_HMoney ) + ( tresult.GetMinutes() / 60.0 )*m_HMoney;
	

	UpdateData(FALSE);

	

}




void CCALPAY::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//caltime();
	CDialog::OnOK();
}

/*
void CCALPAY::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	caltime();
}
*/


void CCALPAY::OnBnClickedResultm()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//caltime();
	UpdateData(TRUE);
	AfxBeginThread(CreateThread, this);
	UpdateData(FALSE);
}

UINT CCALPAY::CreateThread(void * IParam)
{

	CCALPAY *pDlg = (CCALPAY *)IParam;


	pDlg->UpdateData(TRUE);
	SYSTEMTIME st, st1, st2, st3, st4, st5;

	// SYSTEMTIME 구조체에 시간 정보 저장됨
	pDlg->m_starttime.GetTime(&st); // 출근 시간
	// SYSTEMTIME을 CTime형식으로 변환
	CTime t(st);

	pDlg->m_endtime.GetTime(&st1); // 퇴근 시간
	CTime t1(st1);

	pDlg->m_startday.GetTime(&st2); // 출근 날짜
	CTime t2(st2);

	pDlg->m_endday.GetTime(&st3); // 퇴근 날짜
	CTime t3(st3);

	pDlg->m_restday.GetTime(&st4); // 쉬는 날짜
	CTime t7(st4);

	pDlg->m_resttime.GetTime(&st5); // 쉬는 시간
	CTime t8(st5);

	CTimeSpan ts1(0, t8.GetHour(), t8.GetMinute(), t8.GetSecond()); //쉬는 시간 시, 분,초 로 받아온다

	CTime t4(t2.GetYear(), t2.GetMonth(), t2.GetDay(), t.GetHour(), t.GetMinute(), t.GetSecond()); // 출근 시, 분,초 로 받아온다
	CTime t5(t3.GetYear(), t3.GetMonth(), t3.GetDay(), t1.GetHour(), t1.GetMinute(), t1.GetSecond()); // 퇴근 시, 분,초 로 받아온다

	CTimeSpan t6 = t5 - t4; //  퇴근 시간 - 출근 시간
	CTimeSpan tresult = t6 - ts1; // ( 퇴근 시간 - 출근 시간) - 쉬는 시간

	//CString str = tresult.Format(_T("%D: %H : %M : %S")); // 날, 시, 분, 초로 형식 지정
	//MessageBox(str); // 시간 결과 값 메세지 박스로 창띄운다


	pDlg->m_DTMoney = (tresult.GetHours() * (pDlg->m_HMoney)) + (tresult.GetMinutes() / 60.0)* (pDlg->m_HMoney);
	pDlg-> startdate = t2;

	pDlg->UpdateData(FALSE);
	return 0;
}



void CCALPAY::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
	CFont font;
	font.CreateFontW(40, 0, 0, 0, 0, 0, 0, 0, 0, 0, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, _T("배달의민족 주아"));
	GetDlgItem(IDC_STATIC)->SetFont(&font);
}
