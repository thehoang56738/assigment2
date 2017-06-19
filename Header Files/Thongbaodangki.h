#pragma once


// CThongbaodangki dialog

class CThongbaodangki : public CDialog
{
	DECLARE_DYNAMIC(CThongbaodangki)

public:
	CThongbaodangki(CWnd* pParent = NULL);   // standard constructor
	virtual ~CThongbaodangki();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Thongbao1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
