#pragma once


// Cthongbaokhoatk dialog

class Cthongbaokhoatk : public CDialog
{
	DECLARE_DYNAMIC(Cthongbaokhoatk)

public:
	Cthongbaokhoatk(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cthongbaokhoatk();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_THONGBAOKHOATK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
