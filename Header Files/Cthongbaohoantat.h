#pragma once


// Cthongbaohoantat dialog

class Cthongbaohoantat : public CDialog
{
	DECLARE_DYNAMIC(Cthongbaohoantat)

public:
	Cthongbaohoantat(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cthongbaohoantat();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_THONGBAOHOANTAT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
