#pragma once
#include "afxwin.h"


// Cthemvao dialog
class AcceptFile : public CDialog
{
public:
	AcceptFile(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL)
		: CDialog(lpszTemplateName, pParentWnd)
	{
		// your code here
	}

	// other stuff
};

class Cthemvao : public CDialog
{
	DECLARE_DYNAMIC(Cthemvao)

public:
	Cthemvao(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cthemvao();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_THEMVAO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeNoidungsach();
	virtual BOOL OnInitDialog();
protected:
	CEdit edit_themsach;
public:
	afx_msg void OnBnClickedButton1();
protected:
	CEdit edit_luuy;
	CListBox edit_luuy1;
	CListBox edit_luuy2;
	CListBox edit_list69;
public:
	afx_msg void OnLbnSelchangeList69();
};
