#pragma once
#include "afxwin.h"


// Cqlnd_dmk dialog

class Cqlnd_dmk : public CDialog
{
	DECLARE_DYNAMIC(Cqlnd_dmk)

public:
	Cqlnd_dmk(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cqlnd_dmk();
	Cqlnd_dmk(CWnd* pParent, CString strValue);
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QLDN_DOIMATKHAU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CString tensys;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
protected:
	CEdit edit_tendangnhap111;
};
