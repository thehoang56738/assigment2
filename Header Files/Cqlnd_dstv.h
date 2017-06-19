#pragma once
#include "afxwin.h"


// Cqlnd_dstv dialog

class Cqlnd_dstv : public CDialog
{
	DECLARE_DYNAMIC(Cqlnd_dstv)

public:
	Cqlnd_dstv(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cqlnd_dstv();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QLND_DSTV };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
protected:
	CEdit edit_qlnd_dstv_tdn;
};
