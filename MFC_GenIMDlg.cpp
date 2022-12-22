
// MFC_GenIMDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "MFC_GenIM.h"
#include "MFC_GenIMDlg.h"
#include "afxdialogex.h"
#include "Krutki.h"
#include <iostream>
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
	//конструктор

}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CMFCGenIMDlg



CMFCGenIMDlg::CMFCGenIMDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_GENIM_DIALOG, pParent)
	, HAVE_GEMS_EDIT(_T(""))
	, HAVE_KRUTOK_EDIT(_T(""))
	, HAVE_BLESK_EDIT(_T(""))
	, HAVE_ALREADY_EDIT(_T(""))
	, HAVE_LAST_LEGEND_CHECK(FALSE)
	, LEGEND_EDIT(_T(""))
	, MUSOR_EDIT(_T(""))
	, GARANT_EDIT(_T(""))
	, MORE_INFO_EDIT(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCGenIMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, HAVE_GEMS_EDIT);
	DDX_Text(pDX, IDC_EDIT2, HAVE_KRUTOK_EDIT);
	DDX_Text(pDX, IDC_EDIT3, HAVE_BLESK_EDIT);
	DDX_Text(pDX, IDC_EDIT4, HAVE_ALREADY_EDIT);
	DDX_Check(pDX, IDC_CHECK1, HAVE_LAST_LEGEND_CHECK);
	DDX_Text(pDX, IDC_EDIT5, LEGEND_EDIT);
	DDX_Text(pDX, IDC_EDIT7, MUSOR_EDIT);
	DDX_Text(pDX, IDC_EDIT6, GARANT_EDIT);
	DDX_Text(pDX, IDC_EDIT8, MORE_INFO_EDIT);
}

BEGIN_MESSAGE_MAP(CMFCGenIMDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMFCGenIMDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCGenIMDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT4, &CMFCGenIMDlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT3, &CMFCGenIMDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCGenIMDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &CMFCGenIMDlg::OnBnClickedCheck1)
	ON_EN_CHANGE(IDC_EDIT6, &CMFCGenIMDlg::OnEnChangeEdit6)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCGenIMDlg

BOOL CMFCGenIMDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFCGenIMDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCGenIMDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCGenIMDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCGenIMDlg::OnEnChangeEdit1()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CMFCGenIMDlg::OnEnChangeEdit2()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления

}

void CMFCGenIMDlg::OnEnChangeEdit3()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}

void CMFCGenIMDlg::OnEnChangeEdit4()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}





void CMFCGenIMDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	haveGems = _wtoi(HAVE_GEMS_EDIT);
	haveKrutok = _wtoi(HAVE_KRUTOK_EDIT);
	pil = _wtoi(HAVE_BLESK_EDIT);
	already = _wtoi(HAVE_ALREADY_EDIT);
	coinflip = HAVE_LAST_LEGEND_CHECK;


	/*haveGems = atoi(_bstr_t((LPCTSTR)HAVE_GEMS_EDIT));
	haveKrutok = atoi(_bstr_t((LPCTSTR)HAVE_KRUTOK_EDIT));
	pil = atoi(_bstr_t((LPCTSTR)HAVE_BLESK_EDIT));
	already = atoi(_bstr_t((LPCTSTR)HAVE_ALREADY_EDIT));
	coinflip = atoi(_bstr_t((LPCTSTR)HAVE_LAST_LEGEND_CHECK));*/
	UpdateData(FALSE);

	Krutki obj(haveGems, haveKrutok, pil, already, coinflip);
	obj.GetAll(); //можно try добавить

	UpdateData(TRUE);
	
	LEGEND_EDIT += obj.getfiveStar().c_str();
	GARANT_EDIT += obj.getgarant().c_str();
	MUSOR_EDIT +=  obj.getmusor().c_str();
	
	
	for (int i = 0; i < _wtoi(LEGEND_EDIT); i++)
	{
		MORE_INFO_EDIT += "#";
		MORE_INFO_EDIT += to_string(i+1).c_str();
		MORE_INFO_EDIT += "\t|  ";
		MORE_INFO_EDIT += obj.isMusor(i).c_str();
		MORE_INFO_EDIT += "\t| \t";
		MORE_INFO_EDIT += "Осталось на данном этапе: ";
		MORE_INFO_EDIT += obj.getKrstat(i).c_str();
		MORE_INFO_EDIT += "\r\n";
	}

	UpdateData(FALSE);


}


void CMFCGenIMDlg::OnBnClickedCheck1()
{
	
}


void CMFCGenIMDlg::OnEnChangeEdit6() //GARANT_EDIT
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}
