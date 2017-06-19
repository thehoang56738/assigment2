// Cgnmt_sach.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cgnmt_sach.h"
#include "afxdialogex.h"
#include "SecondDlg.h"
#include "Clichsumuonsach.h"
#include "Clichsutrasach.h"
#include <sstream>
// Cgnmt_sach dialog

IMPLEMENT_DYNAMIC(Cgnmt_sach, CDialog)

Cgnmt_sach::Cgnmt_sach(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MUONTRASACH, pParent)
{

}

Cgnmt_sach::~Cgnmt_sach()
{
}
Cgnmt_sach::Cgnmt_sach(CWnd* pParent, CString str)
	: CDialog(IDD_MUONTRASACH, pParent)
{
	tensys = str;
}
void Cgnmt_sach::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LISTMUONSACH, edit_ds_muonsach);
	DDX_Control(pDX, IDC_LISTTRASACH, edit_ds_trasach);
	DDX_Control(pDX, IDC_XNMUONSACH, edit_xn_muonsach);
	DDX_Control(pDX, IDC_DACHONMUONSACH, edit_dc_muonsach);
	DDX_Control(pDX, IDC_DATRASACH, edit_datrasach);
}

BOOL Cgnmt_sach::OnInitDialog()
{
	CDialog::OnInitDialog();
	using namespace std;
	fstream f1;
	f1.open("E:\\data\\listmuonsach.txt");
	while (!f1.eof())
	{
		string ab;
		getline(f1, ab);
		if (ab !="")
		{
			string a = tok(ab);//lấy tên tài khoản
			string b = tok(ab);//Lấy tên sách
			string d = tok(ab);//Lấy số lượng
			//string e = tok(ab);//Lấy ngày tháng
			string ten =a + " :: " + b + " :: " + d + " :: " + ab;
			CString c(ten.c_str());
			edit_ds_muonsach.AddString(c);
		}	
	}
	f1.close();
	f1.open("E:\\data\\list_trasach.txt");
	while (!f1.eof())
	{
		string ab;
		getline(f1, ab);
		if (ab != "")
		{
			string ms = tok(ab);//Lấy mã số
			string e = tok(ab);//lấy tên tài khoản
			string f = tok(ab);//Lấy tên sách
			string g = tok(ab);//lấy số lượng
			string ten = ms + " :: " + e + " :: " + f + " :: " + g + " :: " + ab;
			CString c(ten.c_str());
			edit_ds_trasach.AddString(c);
		}
	}
	f1.close();
	return TRUE;
}
BEGIN_MESSAGE_MAP(Cgnmt_sach, CDialog)
	ON_BN_CLICKED(IDC_XNMUONSACH, &Cgnmt_sach::OnBnClickedXnmuonsach)
	ON_LBN_SELCHANGE(IDC_LISTMUONSACH, &Cgnmt_sach::OnLbnSelchangeListmuonsach)
	ON_BN_CLICKED(IDC_XNMUONSACH2, &Cgnmt_sach::OnBnClickedXnmuonsach2)
	ON_BN_CLICKED(IDC_XNTRASACH, &Cgnmt_sach::OnBnClickedXntrasach)
	ON_BN_CLICKED(IDC_DATRASACHBUTTON, &Cgnmt_sach::OnBnClickedDatrasachbutton)
	ON_LBN_SELCHANGE(IDC_LISTTRASACH, &Cgnmt_sach::OnLbnSelchangeListtrasach)
	ON_BN_CLICKED(IDC_BUTTON1, &Cgnmt_sach::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &Cgnmt_sach::OnBnClickedButton3)
END_MESSAGE_MAP()


// Cgnmt_sach message handlers

void Cgnmt_sach::OnLbnSelchangeListmuonsach()
{
	// TODO: Add your control notification handler code here
	//Lấy phần tử đang được chọn
	int a = edit_ds_muonsach.GetCurSel();
	if (a < 0) return;
	CString b;
	edit_ds_muonsach.GetText(a, b);
	edit_dc_muonsach.SetWindowText(b);
	//Update từ m_txtEdit lên Edit Control
	UpdateData(FALSE);
}
void Cgnmt_sach::OnBnClickedXnmuonsach()
{
	// TODO: Add your control notification handler code here
	using namespace std;
	CString str1;
	edit_dc_muonsach.GetWindowText(str1);
	CT2CA a(str1);
	string xoa(a);

	//xóa list
	edit_ds_muonsach.ResetContent();
	ASSERT(edit_ds_muonsach.GetCount() == 0);
	string tensach = "", tentk;

	string a1 = tok2(xoa);//Lấy têntk
	string b = tok2(xoa);//Lấy tên sách;
	string c = tok2(xoa);//Lấy số lượng còn xoa là ngày tháng
	/*istringstream iss(xoa, istringstream::in);
	string  bien;
	int i = 0;
	while (!iss.eof())
	{
		if (i == 0) iss >> tentk;
		if (i > 0)
		{
			iss >> bien;
			tensach += bien + " ";
		}
		else iss >> bien;
		i++;

	}*/
	//tensach.erase(tensach.size() - 1, tensach.size());

	fstream f1, f2;
	f1.open("E:\\data\\listmuonsach.txt");
	f2.open("E:\\data\\list_chua_duyet.txt",ios::out);
	
	if (xoa == "") return;
	else
	{
		while (!f1.eof())
		{
			string ab;
			getline(f1, ab);
			if (ab == "") continue;
			else
			{
				string tam = a1 + ";" + b + ";" + c + ";" + xoa;
				if (tam.compare(ab) != 0) f2 << ab << endl;
			}
		}
	}
	f1.close();
	f2.close();
	//remove("E:\\listmtsach.txt");
	//rename("E:\\list.txt", "E:\\listmtsach.txt");
	f1.open("E:\\data\\list_chua_duyet.txt");
	while (!f1.eof())
	{
		string ab;
		getline(f1, ab);
		if (ab != "")
		{
			string a = tok(ab);//lấy MSSV
			string b = tok(ab);//Lấy tên sách,
			string c = tok(ab);//lấy số lượng
			string ten = a + " :: " + b + " :: " + c + " :: " + ab;
			CString t(ten.c_str());
			edit_ds_muonsach.AddString(t);
		}
	}
	f1.close();
	remove("E:\\data\\listmuonsach.txt");
	rename("E:\\data\\list_chua_duyet.txt", "E:\\data\\listmuonsach.txt");

}


void Cgnmt_sach::OnBnClickedXnmuonsach2()
{
	// TODO: Add your control notification handler code here
	//remove("E:\\listmtsach.txt");
	using namespace std;
	fstream f1, f2, f3, f4, f5;
	f1.open("E:\\data\\listmuonsach.txt");
	f2.open("E:\\data\\lichsu_muonsach.txt");
	CT2CA k(tensys);
	string tendn(k);
	string tenf5 = "E:\\data\\khachhangmuonsach\\" + tendn + ".txt";
	f5.open(tenf5);
	int i = 1;
	while (!f2.eof())
	{
		string ms;
		getline(f2, ms);
		if (ms != "") i++;
	}
	f2.close();
	f2.open("E:\\data\\lichsu_muonsach.txt", ios::app);
	while (!f1.eof())
	{
		string a;
		getline(f1, a);
		string b = a;
		if (a != "")
		{
			string d = tok(b);
			string tenkhachhang = "E:\\data\\khachhangmuonsach\\" + d + ".txt";
			string tenkhachhang1 = "E:\\data\\khachhangmuonsach\\lichsu_" + d + ".txt";
			f3.open(tenkhachhang, ios::app);
			f4.open(tenkhachhang1, ios::app);
			f3 << to_string(i) + ";" + b << endl;
			f4 << b << endl;
			//a.erase(a.size() - 1, a.size());
			f2 << to_string(i) + ";" + a << "\n";
			i++;
			f3.close();
			f4.close();
		}
	}
	f1.close();
	f2.close();
	edit_ds_muonsach.ResetContent();
	ASSERT(edit_ds_muonsach.GetCount() == 0);
	//f1.open("E:\\list_da_duyet.txt");
	//while (!f1.eof())
	//{
	//	string ab;
	//	getline(f1, ab);
	//	if (ab != "")
	//	{
	//		string a = tok(ab);//lấy MSSV
	//		string b = tok(ab);//Lấy tên sách, ab = 1 trả sách
	//		string ten = a + " :: " + b;
	//		//CString c(ten.c_str());
	//		//edit_ds_trasach.AddString(c);
	//	}
	//}
	//f1.close();
	remove("E:\\data\\listmuonsach.txt");
	f1.open("E:\\data\\listmuonsach.txt", ios::out);
	f1.close();
}


void Cgnmt_sach::OnBnClickedXntrasach()
{
	// TODO: Add your control notification handler code here
	using namespace std;
	std::fstream f1, f2;
	f1.open("E:\\data\\list_trasach.txt");
	/*f2.open("E:\\data\\lichsu_trasach.txt");
	int i = 1;
	while (!f2.eof())
	{
		string ms;
		getline(f2, ms);
		if (ms != "") i++;
	}
	f2.close();*/
	f2.open("E:\\data\\lichsu_trasach.txt", ios::app);
	while (!f1.eof())
	{
		string ab;
		getline(f1, ab);
		string cd = ab;
		if (ab != "")
		{
			//tok(cd);
			f2 << /*to_string(i) + ";" +*/ cd + "\n";// << endl;
			//i++;
			string ms = tok(ab);//Lấy mã số
			string a = tok(ab);//lấy MSSV
			string b = tok(ab);//Lấy tên sách,
			string c = tok(ab);//lấy số lượng
			string ten = ms + " :: " + a + " :: " + b + " :: " + c + " :: " + ab;
			//string a = tok(ab);//lấy MSSV
			//string b = tok(ab);//Lấy tên sách, ab = 1 trả sách
			//string ten = a + " :: " + b;
			CString t(ten.c_str());
			edit_ds_trasach.AddString(t);
		}
	}
	f1.close();
	edit_ds_trasach.ResetContent();
	ASSERT(edit_ds_trasach.GetCount() == 0);
	remove("E:\\data\\list_trasach.txt");
	f1.open("E:\\data\\list_trasach.txt", ios::out);
	f1.close();
}
void Cgnmt_sach::OnLbnSelchangeListtrasach()
{
	// TODO: Add your control notification handler code here
	int a = edit_ds_trasach.GetCurSel();
	if (a < 0) return;
	CString b;
	edit_ds_trasach.GetText(a, b);
	edit_datrasach.SetWindowText(b);
	//Update từ m_txtEdit lên Edit Control
	UpdateData(FALSE);
}

void Cgnmt_sach::OnBnClickedDatrasachbutton()
{
	// TODO: Add your control notification handler code here
	using namespace std;
	CString str1;
	edit_datrasach.GetWindowText(str1);
	CT2CA a(str1);
	string xoa(a);

	//xóa list
	edit_ds_trasach.ResetContent();
	ASSERT(edit_ds_trasach.GetCount() == 0);
	string tensach = "", tentk;
	string ms_ht = tok2(xoa);
	string a1 = tok2(xoa);//Lấy têntk
	string b = tok2(xoa);//Lấy tên sách;
	string c = tok2(xoa);//Lấy số lượng còn xoa là ngày tháng

	fstream f1, f2,f3;
	f1.open("E:\\data\\list_trasach.txt");
	f2.open("E:\\data\\tam.txt", ios::out);
	/*f3.open("E:\\data\\lichsu_trasach.txt");
	int i = 1;
	while (!f3.eof())
	{
		string ms;
		getline(f3, ms);
		if (ms != "") i++;
	}
	f3.close();*/
	f3.open("E:\\data\\lichsu_trasach.txt", ios::app);
	if (xoa == "") return;
	else
	{
		while (!f1.eof())
		{
			string ab;
			getline(f1, ab);
			if (ab == "") continue;
			else
			{
				string tam = ms_ht + ";" + a1 + ";" + b + ";" + c + ";" + xoa;
				if (tam.compare(ab) != 0)
				{
					f2 << ab << endl;
					//f3 << /*to_string(i) + ";" +*/ ab << endl;
					//i++;
				}
				else f3 << /*to_string(i) + ";" +*/ ab << endl;
			}
		}
	}
	f1.close();
	f2.close();
	f3.close();
	remove("E:\\data\\list_trasach.txt");
	rename("E:\\data\\tam.txt", "E:\\data\\list_trasach.txt");
	edit_ds_trasach.ResetContent();
	ASSERT(edit_ds_trasach.GetCount() == 0);
	f1.open("E:\\data\\list_trasach.txt");
	while (!f1.eof())
	{
		string ab;
		getline(f1, ab);
		if (ab != "")
		{
			string ms_ht = tok(ab);
			string a = tok(ab);//lấy MSSV
			string b = tok(ab);//Lấy tên sách,
			string c = tok(ab);//lấy số lượng
			string ten = ms_ht + " :: " + a + " :: " + b + " :: " + c + " :: " + ab;
			//string a = tok(ab);//lấy MSSV
			//string b = tok(ab);//Lấy tên sách
			//string ten = a + " :: " + b;
			CString t(ten.c_str());
			edit_ds_trasach.AddString(t);
		}
	}
	f1.close();
}





void Cgnmt_sach::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	Clichsumuonsach cdm;
	cdm.DoModal();
}


void Cgnmt_sach::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	Clichsutrasach th(NULL, tensys); //
	th.DoModal();
}
