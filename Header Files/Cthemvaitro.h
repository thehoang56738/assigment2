#pragma once
#include "afxwin.h"


// Cthemvaitro dialog

class Cthemvaitro : public CDialog
{
	DECLARE_DYNAMIC(Cthemvaitro)

public:
	Cthemvaitro(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cthemvaitro();
	Cthemvaitro(CWnd* pParent, CString strValue);
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_THEMVAITRO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CString tensys;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
protected:
	CEdit edit_tendangnhap_tvt;
	CEdit edit_matkhau_tvt;
	CButton edit_thuthu_tvt;
	CButton edit_qldn_tvt;
	CEdit edit_themvaitro_nhaplaimk;
};
