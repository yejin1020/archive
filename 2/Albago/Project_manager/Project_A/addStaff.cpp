// addStaff.cpp: 구현 파일
//

#include "stdafx.h"
#include "Project_A.h"
#include "addStaff.h"
#include "afxdialogex.h"


// addStaff 대화 상자

IMPLEMENT_DYNAMIC(addStaff, CDialog)

addStaff::addStaff(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_ADD_STAFF, pParent)
	, m_staffname(_T(""))
	, m_staffage(_T(""))
	, m_stafftime(_T(""))
	, m_staffaccount(_T(""))
	, m_staffphonenum(_T(""))
{

}

addStaff::~addStaff()
{
}

void addStaff::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_staffname);
	DDX_Text(pDX, IDC_EDIT_AGE, m_staffage);
	DDX_Text(pDX, IDC_EDIT_TIME, m_stafftime);
	DDX_Text(pDX, IDC_EDIT_ACCOUNT, m_staffaccount);
	DDX_Text(pDX, IDC_EDIT_PHONENUM, m_staffphonenum);
}


BEGIN_MESSAGE_MAP(addStaff, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// addStaff 메시지 처리기



void addStaff::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
	CFont font;
	font.CreateFontW(25, 0, 0, 0, 0, 0, 0, 0, 0, 0, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, _T("배달의민족 주아"));
	GetDlgItem(IDC_STATIC)->SetFont(&font);
}
