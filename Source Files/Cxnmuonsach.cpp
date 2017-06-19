// Cxnmuonsach.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cxnmuonsach.h"
#include "afxdialogex.h"
#include "SecondDlg.h"
#include "Primary2Dlg.h"
#include "Cdocgia.h"
// Cxnmuonsach dialog

IMPLEMENT_DYNAMIC(Cxnmuonsach, CDialog)

Cxnmuonsach::Cxnmuonsach(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_GIOHANG, pParent)
{

}

Cxnmuonsach::~Cxnmuonsach()
{
}
Cxnmuonsach::Cxnmuonsach(CWnd* pParent, CString str)
	: CDialog(IDD_GIOHANG, pParent)
{
	tensys = str;
}
void Cxnmuonsach::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LISTGIOHANG, edit_listgiohang);
	DDX_Control(pDX, IDC_LOAIBO, edit_xnloaibo);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, edit_datetime);
	//DDX_Control(pDX, IDC_DATETIMEPICKER2, edit_ngaythang);
	DDX_Control(pDX, IDC_EDIT2, edit_ngay);
}
BOOL Cxnmuonsach::OnInitDialog()
{
	CDialog::OnInitDialog();
	using namespace std;
	fstream f1;
	f1.open("E:\\giohang.txt");
	int i = 0;
	while (!f1.eof())
	{
		string a;
		getline(f1, a);
		if (a == "" && i == 0)
		{
			edit_listgiohang.AddString(_T("Giỏ hàng còn trống!"));
			i++;
			continue;
		}
		else if(a!="")
		{
			i++;
			string sach = tok(a);
			string hienthi = sach + " So luong: " + a;
			CString b(hienthi.c_str());
			edit_listgiohang.AddString(b);
		}
	}
	f1.close();
	return TRUE;
}

BEGIN_MESSAGE_MAP(Cxnmuonsach, CDialog)
	ON_LBN_SELCHANGE(IDC_LISTGIOHANG, &Cxnmuonsach::OnLbnSelchangeListgiohang)
	ON_BN_CLICKED(IDC_XNLOAIBO, &Cxnmuonsach::OnBnClickedXnloaibo)
	ON_BN_CLICKED(IDC_DANGKYMUON, &Cxnmuonsach::OnBnClickedDangkymuon)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, &Cxnmuonsach::OnDtnDatetimechangeDatetimepicker1)
END_MESSAGE_MAP()

CString date;
void Cxnmuonsach::OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: Add your control notification handler code here
	CString a;
	GetDlgItemText(IDC_DATETIMEPICKER1,a);
	edit_ngay.SetWindowText(a);
	*pResult = 0;
}
// Cxnmuonsach message handlers


void Cxnmuonsach::OnLbnSelchangeListgiohang()
{
	// TODO: Add your control notification handler code here
	int a = edit_listgiohang.GetCurSel();
	if (a < 0) return;
	CString b;
	edit_listgiohang.GetText(a, b);
	edit_xnloaibo.SetWindowText(b);
	//Update từ m_txtEdit lên Edit Control
	UpdateData(FALSE);
}

void Cxnmuonsach::OnBnClickedXnloaibo()
{
	// TODO: Add your control notification handler code here
	using namespace std;
	CString str1;
	edit_xnloaibo.GetWindowText(str1);
	CT2CA a(str1);
	string loaibo(a);

	//xóa list
	edit_listgiohang.ResetContent();
	ASSERT(edit_listgiohang.GetCount() == 0);
	fstream f1,f2;
	f1.open("E:\\giohang.txt");
	f2.open("E:\\tam.txt", ios::out);
	while (!f1.eof())
	{
		string b, c;
		getline(f1, b);
		c = b;
		string bien = tok(b);
		string ab = bien + " So luong: " + b;
		if (b != "") 
		{
			
			if (ab.compare(loaibo) != 0)
			{
				f2 << c << endl;
			}
		}  
	}
	f1.close();
	f2.close();
	remove("E:\\giohang.txt");
	rename("E:\\tam.txt", "E:\\giohang.txt");
	f1.open("E:\\giohang.txt");
	int i = 0;
	while (!f1.eof())
	{
		string a;
		getline(f1, a);
		if (a == "" && i == 0)
		{
			edit_listgiohang.AddString(_T("Giỏ hàng còn trống!"));
			continue;
		}
		else if (a!="")
		{
			i++;
			string sach = tok(a);
			string hienthi = sach + " So luong: " + a;
			CString b(hienthi.c_str());
			edit_listgiohang.AddString(b);
		}
	}
	f1.close();
}


void Cxnmuonsach::OnBnClickedDangkymuon()
{
	// TODO: Add your control notification handler code here
	//xóa list
	using namespace std;
	int a = edit_listgiohang.GetCount();
	edit_listgiohang.ResetContent();
	ASSERT(edit_listgiohang.GetCount() == 0);
	
	fstream f1,f2,f3;
	f1.open("E:\\giohang.txt");
	f2.open("E:\\listmuonsach.txt", ios::app);
	f3.open("E:\\khachhang\\luutendangnhap.txt");
	string b;
	getline(f3, b);

	//chuyển date thành string
	CT2CA r1(date);
	string ngaythang(r1);
	while (!f1.eof())
	{
		string a;
		getline(f1, a);
		//int a = edit_datetime.GetTime();
		if (a != "") f2 << b + ";" + a + ";" + ngaythang << endl;
	}
	if (a != 1) edit_listgiohang.AddString(_T("Đã Gửi Yêu Cầu Mượn Sách Đến Thủ Thư!"));
	if (a == 1) edit_listgiohang.AddString(_T("Giỏ Hàng Trống!"));
	f1.close();
	f2.close();
	remove("E:\\giohang.txt");
	f1.open("E:\\giohang.txt", ios::out);
	f1.close();
}


