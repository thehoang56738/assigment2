#pragma once


// Cthongbaosaiid dialog

class Cthongbaosaiid : public CDialog
{
	DECLARE_DYNAMIC(Cthongbaosaiid)

public:
	Cthongbaosaiid(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cthongbaosaiid();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_THONGBAOSAIID };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
