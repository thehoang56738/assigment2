#pragma once
#include "afxwin.h"


// Cthuthu_xoasach dialog

class Cthuthu_xoasach : public CDialog
{
	DECLARE_DYNAMIC(Cthuthu_xoasach)

public:
	Cthuthu_xoasach(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cthuthu_xoasach();
	virtual BOOL Cthuthu_xoasach::OnInitDialog();
	Cthuthu_xoasach(CWnd* pParent, CString strValue);
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TTXOASACH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CString tensys;
	DECLARE_MESSAGE_MAP()
	CEdit edit_tensach;
public:
	afx_msg void OnBnClickedOk();
protected:
	CListBox edit_list_xoa;
	CListBox edit_listsach;
public:
	afx_msg void OnLbnSelchangeList1();
};
