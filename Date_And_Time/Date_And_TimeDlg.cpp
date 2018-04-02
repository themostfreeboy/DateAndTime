
// Date_And_TimeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Date_And_Time.h"
#include "Date_And_TimeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CDate_And_TimeDlg* dlg_backup;


// CDate_And_TimeDlg 对话框




CDate_And_TimeDlg::CDate_And_TimeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDate_And_TimeDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDate_And_TimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PSECOND, m_ctrlProgress);
}

BEGIN_MESSAGE_MAP(CDate_And_TimeDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BEXIT, &CDate_And_TimeDlg::OnBnClickedBexit)
END_MESSAGE_MAP()


// CDate_And_TimeDlg 消息处理程序

BOOL CDate_And_TimeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	UpdateData(FALSE);
    m_ctrlProgress.SetRange(0,59);//设置进度条的范围
    m_ctrlProgress.SetStep(1);//设置进度条的每一步的增量

	SYSTEMTIME SystemTime;
	GetLocalTime(&SystemTime);//获取系统时间
	int year=SystemTime.wYear;
	int month=SystemTime.wMonth;
	int day=SystemTime.wDay;
	int week=SystemTime.wDayOfWeek;
	int hour=SystemTime.wHour;
	int minute=SystemTime.wMinute;
	int second=SystemTime.wSecond;
	CString cstr_date=_T("");
	CString cstr_time=_T("");
	switch(week)
	{
	    case 0:{cstr_date.Format(_T("当前日期：%04d年%02d月%02d日星期日"),year,month,day);break;}
		case 1:{cstr_date.Format(_T("当前日期：%04d年%02d月%02d日星期一"),year,month,day);break;}
		case 2:{cstr_date.Format(_T("当前日期：%04d年%02d月%02d日星期二"),year,month,day);break;}
		case 3:{cstr_date.Format(_T("当前日期：%04d年%02d月%02d日星期三"),year,month,day);break;}
		case 4:{cstr_date.Format(_T("当前日期：%04d年%02d月%02d日星期四"),year,month,day);break;}
		case 5:{cstr_date.Format(_T("当前日期：%04d年%02d月%02d日星期五"),year,month,day);break;}
		case 6:{cstr_date.Format(_T("当前日期：%04d年%02d月%02d日星期六"),year,month,day);break;}
		default:{break;}
	}
	cstr_time.Format(_T("当前时间：%02d:%02d:%02d"),hour,minute,second);
	SetDlgItemText(IDC_SDATE,cstr_date);
	SetDlgItemText(IDC_STIME,cstr_time);
	m_ctrlProgress.SetPos(second);//设置进度条的当前位置
	dlg_backup=this;
	HANDLE thread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)proc,NULL,0,NULL);//启动多线程

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDate_And_TimeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDate_And_TimeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDate_And_TimeDlg::OnBnClickedBexit()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}


UINT proc(LPVOID pParam)
{
	SYSTEMTIME SystemTime;
	GetLocalTime(&SystemTime);//获取系统时间
	int year;
	int month;
	int day;
	int week;
	int hour;
	int minute;
	int oldsecond=SystemTime.wSecond;
	int newsecond=SystemTime.wSecond;
	CString cstr_date=_T("");
	CString cstr_time=_T("");
    while(1)
    {
	    GetLocalTime(&SystemTime);//获取系统时间
		newsecond=SystemTime.wSecond;
		if(newsecond!=oldsecond)
		{
			oldsecond=newsecond;
			year=SystemTime.wYear;
	        month=SystemTime.wMonth;
	        day=SystemTime.wDay;
	        week=SystemTime.wDayOfWeek;
	        hour=SystemTime.wHour;
	        minute=SystemTime.wMinute;
			switch(week)
	        {
	            case 0:{cstr_date.Format(_T("当前日期：%04d年%02d月%02d日星期日"),year,month,day);break;}
		        case 1:{cstr_date.Format(_T("当前日期：%04d年%02d月%02d日星期一"),year,month,day);break;}
		        case 2:{cstr_date.Format(_T("当前日期：%04d年%02d月%02d日星期二"),year,month,day);break;}
		        case 3:{cstr_date.Format(_T("当前日期：%04d年%02d月%02d日星期三"),year,month,day);break;}
		        case 4:{cstr_date.Format(_T("当前日期：%04d年%02d月%02d日星期四"),year,month,day);break;}
		        case 5:{cstr_date.Format(_T("当前日期：%04d年%02d月%02d日星期五"),year,month,day);break;}
		        case 6:{cstr_date.Format(_T("当前日期：%04d年%02d月%02d日星期六"),year,month,day);break;}
		        default:{break;}
	        }
	        cstr_time.Format(_T("当前时间：%02d:%02d:%02d"),hour,minute,newsecond);
	        dlg_backup->SetDlgItemText(IDC_SDATE,cstr_date);
	        dlg_backup->SetDlgItemText(IDC_STIME,cstr_time);
			dlg_backup->m_ctrlProgress.SetPos(newsecond);//设置进度条的当前位置
        }
	}
}