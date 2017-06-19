#pragma once
#include "afxwin.h"


// Cqlnd_xoa dialog

class Cqlnd_xoa : public CDialog
{
	DECLARE_DYNAMIC(Cqlnd_xoa)

public:
	Cqlnd_xoa(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cqlnd_xoa();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QLND_XOA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedQlndXoaXoa();
protected:
	CEdit edit_qlnd_xoa_tdn;
};
