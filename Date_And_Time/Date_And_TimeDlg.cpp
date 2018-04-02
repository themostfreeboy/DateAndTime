
// Date_And_TimeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Date_And_Time.h"
#include "Date_And_TimeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CDate_And_TimeDlg* dlg_backup;


// CDate_And_TimeDlg �Ի���




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


// CDate_And_TimeDlg ��Ϣ�������

BOOL CDate_And_TimeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	UpdateData(FALSE);
    m_ctrlProgress.SetRange(0,59);//���ý������ķ�Χ
    m_ctrlProgress.SetStep(1);//���ý�������ÿһ��������

	SYSTEMTIME SystemTime;
	GetLocalTime(&SystemTime);//��ȡϵͳʱ��
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
	    case 0:{cstr_date.Format(_T("��ǰ���ڣ�%04d��%02d��%02d��������"),year,month,day);break;}
		case 1:{cstr_date.Format(_T("��ǰ���ڣ�%04d��%02d��%02d������һ"),year,month,day);break;}
		case 2:{cstr_date.Format(_T("��ǰ���ڣ�%04d��%02d��%02d�����ڶ�"),year,month,day);break;}
		case 3:{cstr_date.Format(_T("��ǰ���ڣ�%04d��%02d��%02d��������"),year,month,day);break;}
		case 4:{cstr_date.Format(_T("��ǰ���ڣ�%04d��%02d��%02d��������"),year,month,day);break;}
		case 5:{cstr_date.Format(_T("��ǰ���ڣ�%04d��%02d��%02d��������"),year,month,day);break;}
		case 6:{cstr_date.Format(_T("��ǰ���ڣ�%04d��%02d��%02d��������"),year,month,day);break;}
		default:{break;}
	}
	cstr_time.Format(_T("��ǰʱ�䣺%02d:%02d:%02d"),hour,minute,second);
	SetDlgItemText(IDC_SDATE,cstr_date);
	SetDlgItemText(IDC_STIME,cstr_time);
	m_ctrlProgress.SetPos(second);//���ý������ĵ�ǰλ��
	dlg_backup=this;
	HANDLE thread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)proc,NULL,0,NULL);//�������߳�

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDate_And_TimeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDate_And_TimeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDate_And_TimeDlg::OnBnClickedBexit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}


UINT proc(LPVOID pParam)
{
	SYSTEMTIME SystemTime;
	GetLocalTime(&SystemTime);//��ȡϵͳʱ��
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
	    GetLocalTime(&SystemTime);//��ȡϵͳʱ��
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
	            case 0:{cstr_date.Format(_T("��ǰ���ڣ�%04d��%02d��%02d��������"),year,month,day);break;}
		        case 1:{cstr_date.Format(_T("��ǰ���ڣ�%04d��%02d��%02d������һ"),year,month,day);break;}
		        case 2:{cstr_date.Format(_T("��ǰ���ڣ�%04d��%02d��%02d�����ڶ�"),year,month,day);break;}
		        case 3:{cstr_date.Format(_T("��ǰ���ڣ�%04d��%02d��%02d��������"),year,month,day);break;}
		        case 4:{cstr_date.Format(_T("��ǰ���ڣ�%04d��%02d��%02d��������"),year,month,day);break;}
		        case 5:{cstr_date.Format(_T("��ǰ���ڣ�%04d��%02d��%02d��������"),year,month,day);break;}
		        case 6:{cstr_date.Format(_T("��ǰ���ڣ�%04d��%02d��%02d��������"),year,month,day);break;}
		        default:{break;}
	        }
	        cstr_time.Format(_T("��ǰʱ�䣺%02d:%02d:%02d"),hour,minute,newsecond);
	        dlg_backup->SetDlgItemText(IDC_SDATE,cstr_date);
	        dlg_backup->SetDlgItemText(IDC_STIME,cstr_time);
			dlg_backup->m_ctrlProgress.SetPos(newsecond);//���ý������ĵ�ǰλ��
        }
	}
}