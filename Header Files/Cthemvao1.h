#pragma once
#include "afxwin.h"


// Cthemvao1 dialog

class Cthemvao1 : public CDialogEx
{
	DECLARE_DYNAMIC(Cthemvao1)

public:
	Cthemvao1(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cthemvao1();
	Cthemvao1(CWnd* pParent, CString strValue);
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_THEMVAO1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CString tensys;
	DECLARE_MESSAGE_MAP()
	CEdit edit_tensach1;
public:
	afx_msg void OnBnClickedCapnhatsach();
	virtual BOOL OnInitDialog();
protected:
	CListBox edit_listluuy;
	CListBox edit_thuthu_listsach;
public:
	afx_msg void OnLbnSelchangeThuthuListtensach();
};
