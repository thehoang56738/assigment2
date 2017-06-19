#pragma once


// CThirdDlg dialog

class CThirdDlg : public CDialog
{
	DECLARE_DYNAMIC(CThirdDlg)

public:
	CThirdDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CThirdDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_THIRD_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
