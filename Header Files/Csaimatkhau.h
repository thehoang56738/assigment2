#pragma once


// Csaimatkhau dialog

class Csaimatkhau : public CDialog
{
	DECLARE_DYNAMIC(Csaimatkhau)

public:
	Csaimatkhau(CWnd* pParent = NULL);   // standard constructor
	virtual ~Csaimatkhau();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SAIMATKHAU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
