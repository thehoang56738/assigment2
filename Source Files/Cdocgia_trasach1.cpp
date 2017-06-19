// Cdocgia_trasach1.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cdocgia_trasach1.h"
#include "afxdialogex.h"


// Cdocgia_trasach1 dialog

IMPLEMENT_DYNAMIC(Cdocgia_trasach1, CDialog)

Cdocgia_trasach1::Cdocgia_trasach1(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DOCGIATRASACH, pParent)
{

}

Cdocgia_trasach1::~Cdocgia_trasach1()
{
}
Cdocgia_trasach1::Cdocgia_trasach1(CWnd* pParent, CString str)
	: CDialog(IDD_DOCGIATRASACH, pParent)
{
	tensys = str;
}
void Cdocgia_trasach1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, edit_chontime);
	DDX_Control(pDX, IDC_LIST1, edit_list);
	DDX_Control(pDX, IDC_EDIT1, edit_chon);
}

BOOL Cdocgia_trasach1::OnInitDialog()
{
	CDialog::OnInitDialog();
	using namespace std;
	fstream f1;
	CT2CA ten(tensys);
	string b(ten);
	string a = "E:\\data\\khachhangmuonsach\\" + b + ".txt";
	f1.open(a, ios::in);
	while (!f1.eof())
	{
		string ab;
		getline(f1, ab);
		if (ab != "")
		{
			string ms = tok(ab);
			string e = tok(ab);//lấy tên 
			string f = tok(ab);//Lấy môn học
			string g = tok(ab); //lấy so lượng
			string ten = ms + " :: " + e + " :: " + f +" :: " + g;
			CString c(ten.c_str());
			edit_list.AddString(c);
		}
	}
	f1.close();
	//f2.close();
	CString t;
	GetDlgItemText(IDC_DATETIMEPICKER2, t);
	edit_chontime.SetWindowText(t);
	return TRUE;
}
BEGIN_MESSAGE_MAP(Cdocgia_trasach1, CDialog)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER2, &Cdocgia_trasach1::OnDtnDatetimechangeDatetimepicker2)
	ON_LBN_SELCHANGE(IDC_LIST1, &Cdocgia_trasach1::OnLbnSelchangeList11)
	ON_BN_CLICKED(IDC_DOCGIATRASACH, &Cdocgia_trasach1::OnBnClickedDocgiatrasach1)
	ON_BN_CLICKED(IDC_BUTTONTRAALL, &Cdocgia_trasach1::OnBnClickedButtontraall)
END_MESSAGE_MAP()


// Cdocgia_trasach1 message handlers






void Cdocgia_trasach1::OnDtnDatetimechangeDatetimepicker2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void Cdocgia_trasach1::OnLbnSelchangeList11()
{
	// TODO: Add your control notification handler code here
	int a = edit_list.GetCurSel();
	if (a < 0) return;
	CString b;
	edit_list.GetText(a, b);
	edit_chon.SetWindowText(b);
	//Update từ m_txtEdit lên Edit Control
	UpdateData(FALSE);
}


void Cdocgia_trasach1::OnBnClickedDocgiatrasach1()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	using namespace std;
	//xóa list
	edit_list.ResetContent();
	ASSERT(edit_list.GetCount() == 0);
	CString str;
	edit_chon.GetWindowText(str);
	CT2CA r(str);
	string chuoi(r);

	CString ti;
	edit_chontime.GetWindowText(ti);
	CT2CA tp(ti);
	string time(tp);

	if (chuoi == "") return;
	string strms = tok2(chuoi);//lấy mã số
	string str1 = tok2(chuoi);//cắt lấy tên môn học
	string str3 = tok2(chuoi);
	//string str4 = tok2(chuoi);
	string str2 = strms + ";"+ str1 + ";" + str3 + ";" +  chuoi ;
	fstream f1, f2, f3, f4 ,f5 , f6 , f7;
	CT2CA ten(tensys);
	string b(ten);
	//string a = "E:\\data\\khachhangmuonsach\\lichsu_" + b + ".txt";
	string c = "E:\\data\\khachhangmuonsach\\" + b + ".txt";
	string data = str1 + ";" + str3 + ";" + time;
	//mở file lịch sử mượn
	//f1.open(a, ios::app);
	//mở file tên tài khoản
	f3.open(c);
	// file tạm thời
	f4.open("E:\\data\\khachhangmuonsach\\tam.txt", ios::out);
	// lịch sửu trả sách
	f5.open("E:\\data\\list_trasach.txt",ios::app);

	string t1 = tok_ngay(chuoi); int thang1 = stoi(t1);
	string n1 = tok_ngay(chuoi); int ngay1 = stoi(n1);
	int nam1 = stoi(chuoi);
	while (!f3.eof())
	{ 
		string d;
		getline(f3, d);
		if (d != "")
		{
			//f1 << d << endl;
			if (d.compare(str2) != 0)
				f4 << d << endl;
			else
			{
				f5 << strms + ";" + b + ";" + data << endl;//continue;
				string ms = tok(d);
				string ts = tok(d);
				string sl = tok(d);
				string t2 = tok_ngay(d); int thang2 = stoi(t2);
				string n2 = tok_ngay(d); int ngay2 = stoi(n2);
				int nam2 = stoi(d);
				f6.open("E:\\data\\tttk.txt");
				f7.open("E:\\data\\tam.txt", ios::out);
				while (!f6.eof())
				{
					string gr;
					getline(f6, gr);
					if (gr!="")
					{
						string th = gr;
						string ms = tok(gr);
						string sotk = tok(gr);
						string active = tok(gr);
						string tentk = tok(gr);
						if (tentk.compare(b)==0)
						{
							if (nam2 == nam1)
							{
								if (thang2 - thang1 == 5 && ngay2 - ngay1 > 3)
									f7 << ms + ";" + sotk + ";" + "1;" + tentk + ";" + gr << endl;
								else if (thang2 - thang1 > 5)
									f7 << ms + ";" + sotk + ";" + "1;" + tentk + ";" + gr << endl;
								else continue;
							}
							else
							{
								int kt_thang = 12 - thang2 + thang1;
								int kt_ngay = ngay2 + ngay1;
								if (kt_thang > 5)
									f7 << ms + ";" + sotk + ";" + "1;" + tentk + ";" + gr<<endl;
								else
								{
									if (kt_thang == 4 && kt_ngay > 30)
										f7 << ms + ";" + sotk + ";" + "1;" + tentk + ";" + gr <<endl;
									else continue;
								}
							}
						}
						else f7 << th << endl;
					}
					else continue;
				}
				f6.close();
				f7.close();
				remove("E:\\data\\tttk.txt");
				rename("E:\\data\\tam.txt", "E:\\data\\tttk.txt");
			}
		}
	}
	//f1.close();
	//f2.close();
	f3.close();
	f4.close();
	f5.close();
	const char* s = c.c_str();
	remove(s);
	rename("E:\\data\\khachhangmuonsach\\tam.txt", s);
	f1.open(c);
	int i = 0;
	while (!f1.eof())
	{
		string a;
		getline(f1, a);
		if (a == "" && i == 0)
		{
			edit_list.AddString(_T("Danh sách còn trống!"));
			continue;
		}
		else if (a != "")
		{
			i++;
			string ms = tok(a);
			string sach = tok(a);
			string t = tok(a);
			string hienthi = ms + " :: " + sach + " :: " + t +" :: "+ a;
			CString b(hienthi.c_str());
			edit_list.AddString(b);
		}
	}
	f1.close();
	CString t;
	GetDlgItemText(IDC_DATETIMEPICKER2, t);
	edit_chontime.SetWindowText(t);
}
void Cdocgia_trasach1::OnBnClickedButtontraall()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	using namespace std;
	//xóa list
	edit_list.ResetContent();
	ASSERT(edit_list.GetCount() == 0);

	CString ti;
	edit_chontime.GetWindowText(ti);
	CT2CA tp(ti);
	string time(tp);

	fstream f1, f2, f3, f4, f5;
	/*f2.open("E:\\data\\khachhang\\luutendangnhap.txt");
	string b;
	getline(f2, b);*/
	CT2CA ten(tensys);
	string b(ten);
	//string a = "E:\\data\\khachhangmuonsach\\lichsu_" + b + ".txt";
	string c = "E:\\data\\khachhangmuonsach\\" + b + ".txt";
	//f1.open(a, ios::app);
	f3.open(c);
	//f4.open("E:\\data\\khachhangmuonsach\\tam.txt", ios::out);
	f5.open("E:\\data\\list_trasach.txt", ios::app);
	while (!f3.eof())
	{
		string d;
		getline(f3, d);
		if (d != "")
		{
			string tam = d;
			string ms = tok(d);
			string str1 = tok(d);
			string str2 = tok(d);
			string str3 =  str1 + ";" + str2 + ";" + time;
			//f1 << d << endl;
			//if (d.compare(str2) != 0)
			f4 << tam << endl;
			f5 << ms + ";" + b + ";" + str3 << endl;//continue;
		}
	}
	//f1.close();11111
	//f2.close();
	f3.close();
	//f4.close();
	f5.close();
	const char* s = c.c_str();
	remove(s);
	rename("E:\\data\\khachhangmuonsach\\tam.txt", s);
	edit_list.AddString(_T("Danh sách còn trống!"));
	f1.open(c, ios::out);
	f1.close();
	CString t;
	GetDlgItemText(IDC_DATETIMEPICKER2, t);
	edit_chontime.SetWindowText(t);
}
