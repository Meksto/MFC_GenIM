
// MFC_GenIM.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCGenIMApp:
// Сведения о реализации этого класса: MFC_GenIM.cpp
//

class CMFCGenIMApp : public CWinApp
{
public:
	CMFCGenIMApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCGenIMApp theApp;
