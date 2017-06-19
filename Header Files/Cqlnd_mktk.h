#pragma once
#include "afxwin.h"


// Cqlnd_mktk dialog

class Cqlnd_mktk : public CDialog
{
	DECLARE_DYNAMIC(Cqlnd_mktk)

public:
	Cqlnd_mktk(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cqlnd_mktk();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QLND_MKTK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedQlndMktkKtk();
	afx_msg void OnBnClickedQlndMktkMtk();
protected:
	CEdit edit_qlnd_mktk_tdn;
};
