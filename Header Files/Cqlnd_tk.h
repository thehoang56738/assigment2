#pragma once
#include "afxwin.h"


// Cqlnd_tk dialog

class Cqlnd_tk : public CDialog
{
	DECLARE_DYNAMIC(Cqlnd_tk)

public:
	Cqlnd_tk(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cqlnd_tk();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QLND_TK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
protected:
	CEdit edit_qlnd_tk_tdn;
	CEdit edit_qlnd_tk_hvt;
	CEdit edit_qlnd_tk_mssv;
	CEdit edit_qlnd_tk_ns;
	CEdit edit_qlnd_tk_em;
	CEdit edit_qlnd_tk_mstk;
	CEdit edit_qlnd_tk_dstk;
};
