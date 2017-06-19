#pragma once
#include "afxwin.h"


// Cthuthu dialog

class Cthuthu : public CDialog
{
	DECLARE_DYNAMIC(Cthuthu)

public:
	Cthuthu(CWnd* pParent = NULL);   // standard constructor
	Cthuthu(CWnd* pParent, CString strValue);
	virtual ~Cthuthu();
	virtual BOOL OnInitDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_THUTHU };
#endif

protected:
	CString tensys;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	CEdit edit_thuthu_tensys;
	CEdit edit_thongbaothuthu;
public:
	afx_msg void OnBnClickedThuthuthemvao();
	afx_msg void OnBnClickedThuthutimkiem();
	afx_msg void OnBnClickedThuthuxoasach();
	afx_msg void OnBnClickedGhinhanmuontra();
	afx_msg void OnEnChangeThongbaothuthu();
};
