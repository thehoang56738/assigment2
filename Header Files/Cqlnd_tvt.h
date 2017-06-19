#pragma once
#include "afxwin.h"


// Cqlnd_tvt dialog

class Cqlnd_tvt : public CDialog
{
	DECLARE_DYNAMIC(Cqlnd_tvt)

public:
	Cqlnd_tvt(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cqlnd_tvt();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QLND_TVT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	CEdit edit_qlnd_tvt_tdn;
	CButton edit_qlnd_tvt_thuthu;
	CButton edit_qlnd_tvt_qlnd;
public:
	afx_msg void OnBnClickedQlndTvtTvt();
protected:
	CButton edit_qlnd_tvt_hvt;
public:
	afx_msg void OnBnClickedQlndTvtHvt();
};
