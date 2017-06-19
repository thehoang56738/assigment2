// Cmuonsach.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cmuonsach.h"
#include "afxdialogex.h"


// Cmuonsach dialog

IMPLEMENT_DYNAMIC(Cmuonsach, CDialog)

Cmuonsach::Cmuonsach(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_GIOHANG1, pParent)
{

}

Cmuonsach::~Cmuonsach()
{
}
Cmuonsach::Cmuonsach(CWnd* pParent, CString str)
	: CDialog(IDD_GIOHANG1, pParent)
{
	tensys = str;
}
void Cmuonsach::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, edit_time);
	DDX_Control(pDX, IDC_EDIT1, edit_chontime);
	DDX_Control(pDX, IDC_LIST1, edit_listhang);
	DDX_Control(pDX, IDC_EDIT2, edit_chonxoa);
}
BOOL Cmuonsach::OnInitDialog()
{
	CDialog::OnInitDialog();
	using namespace std;
	fstream f1;
	f1.open("E:\\data\\giohang.txt");
	int i = 0;
	while (!f1.eof())
	{
		string a;
		getline(f1, a);
		if (a == "" && i == 0)
		{
			edit_listhang.AddString(_T("Giỏ hàng còn trống!"));
			i++;
			continue;
		}
		else if (a != "")
		{
			i++;
			string sach = tok(a);
			string hienthi = sach + " So luong: " + a;
			CString b(hienthi.c_str());
			edit_listhang.AddString(b);
		}
	}
	f1.close();
	CString a;
	GetDlgItemText(IDC_DATETIMEPICKER1, a);
	edit_chontime.SetWindowText(a);
	return TRUE;
}

void Cmuonsach::OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
BEGIN_MESSAGE_MAP(Cmuonsach, CDialog)
	ON_BN_CLICKED(IDC_BUTTONDANGKY, &Cmuonsach::OnBnClickedButtondangky)
	ON_BN_CLICKED(IDC_BUTTONLOAIBO, &Cmuonsach::OnBnClickedButtonloaibo)
//	ON_LBN_SELCHANGE(IDC_LISTGIOHANG1, &Cmuonsach::OnLbnSelchangeListgiohang1)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, &Cmuonsach::OnDtnDatetimechangeDatetimepicker1)
	ON_LBN_SELCHANGE(IDC_LIST1, &Cmuonsach::OnLbnSelchangeList1)
	ON_EN_CHANGE(IDC_EDIT1, &Cmuonsach::OnEnChangeEdit1)
END_MESSAGE_MAP()


// Cmuonsach message handlers
void Cmuonsach::OnLbnSelchangeListgiohang1()
{
	// TODO: Add your control notification handler code here
	
}

void Cmuonsach::OnBnClickedButtondangky()
{
	// TODO: Add your control notification handler code here
	//xóa list
	using namespace std;
	int a = edit_listhang.GetCount();
	edit_listhang.ResetContent();
	ASSERT(edit_listhang.GetCount() == 0);

	fstream f1, f2, f3, f4;
	f1.open("E:\\data\\giohang.txt");
	f2.open("E:\\data\\listmuonsach.txt", ios::app);
	//f3.open("E:\\data\\khachhang\\luutendangnhap.txt");

	/*string b;
	getline(f3, b);*/
	CT2CA ten(tensys);
	string b(ten);
	//string tenf4 = "E:\\data\\khachhangmuonsach\\" + b + ".txt";
	//f4.open(tenf4, ios::app);
	while (!f1.eof())
	{
		string a;
		getline(f1, a);
		CString ab;
		edit_chontime.GetWindowText(ab);
		CT2CA r1(ab);
		string ngaythang(r1);
		if (a != "")
		{
			f2 << b + ";" + a + ";" + ngaythang << endl;
			//f4 << a + ";" + ngaythang << endl;
		}
	}
	if (a != 1) edit_listhang.AddString(_T("Đã Gửi Yêu Cầu Mượn Sách Đến Thủ Thư!"));
	if (a == 1) edit_listhang.AddString(_T("Giỏ Hàng Trống!"));
	f1.close();
	f2.close();
	//f3.close();
	remove("E:\\data\\giohang.txt");
	f1.open("E:\\data\\giohang.txt", ios::out);
	f1.close();
}

void Cmuonsach::OnBnClickedButtonloaibo()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	using namespace std;
	CString str1;
	edit_chonxoa.GetWindowText(str1);
	CT2CA a(str1);
	string loaibo(a);

	//xóa list
	edit_listhang.ResetContent();
	ASSERT(edit_listhang.GetCount() == 0);
	fstream f1, f2;
	f1.open("E:\\data\\giohang.txt");
	f2.open("E:\\data\\tam.txt", ios::out);
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
	remove("E:\\data\\giohang.txt");
	rename("E:\\data\\tam.txt", "E:\\data\\giohang.txt");
	f1.open("E:\\data\\giohang.txt");
	int i = 0;
	while (!f1.eof())
	{
		string a;
		getline(f1, a);
		if (a == "" && i == 0)
		{
			edit_listhang.AddString(_T("Giỏ hàng còn trống!"));
			continue;
		}
		else if (a != "")
		{
			i++;
			string sach = tok(a);
			string hienthi = sach + " So luong: " + a;
			CString b(hienthi.c_str());
			edit_listhang.AddString(b);
		}
	}
	f1.close();
	UpdateData(FALSE);
}


void Cmuonsach::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
	int a = edit_listhang.GetCurSel();
	if (a < 0) return;
	CString b;
	edit_listhang.GetText(a, b);
	edit_chonxoa.SetWindowText(b);
	//Update từ m_txtEdit lên Edit Control
	UpdateData(FALSE);
}


void Cmuonsach::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
