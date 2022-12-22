
// MFC_GenIMDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CMFCGenIMDlg
class CMFCGenIMDlg : public CDialogEx
{
// Создание
public:
	CMFCGenIMDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_GENIM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP();

	int haveGems;
	int haveKrutok;
	int pil;
	int already;
	bool coinflip;
public:
	CString HAVE_GEMS_EDIT;
	CString HAVE_KRUTOK_EDIT;
	CString HAVE_BLESK_EDIT;
	CString HAVE_ALREADY_EDIT;
	BOOL HAVE_LAST_LEGEND_CHECK;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCheck1();
	CString LEGEND_EDIT;
	CString MUSOR_EDIT;
	CString GARANT_EDIT;
	afx_msg void OnEnChangeEdit6();
	CString MORE_INFO_EDIT;
};
