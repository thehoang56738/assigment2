// Cdocgia_trasach.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cdocgia_trasach.h"
#include "afxdialogex.h"


// Cdocgia_trasach dialog

IMPLEMENT_DYNAMIC(Cdocgia_trasach, CDialog)

Cdocgia_trasach::Cdocgia_trasach(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DOCGIATRASACH, pParent)
{

}

Cdocgia_trasach::~Cdocgia_trasach()
{
}

void Cdocgia_trasach::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, edit_list);
	DDX_Control(pDX, IDC_EDIT1, edit_chon);
	DDX_Control(pDX, IDC_EDIT2, edit_chontime);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, edit_time);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, edit_time1);
}

BOOL Cdocgia_trasach::OnInitDialog()
{
	CDialog::OnInitDialog();
	//using namespace std;
	//fstream f1, f2;
	//f2.open("E:\\data\\khachhang\\luutendangnhap.txt");

	//string b;
	//getline(f2, b);
	//string a = "E:\\data\\khachhangmuonsach\\" + b + ".txt";
	//f1.open(a, ios::in);
	//while (!f1.eof())
	//{
	//	string ab;
	//	getline(f1, ab);
	//	if (ab != "")
	//	{
	//		string e = tok(ab);//lấy môn học ab là ngày tháng
	//		string ten = e + " :: " + ab;
	//		CString c(ten.c_str());
	//		edit_list.AddString(c);
	//	}
	//}
	//f1.close();
	//f2.close();
	/*CString t;
	GetDlgItemText(IDC_DATETIMEPICKER2, t);
	edit_chontime.SetWindowText(t);*/
	return TRUE;
}

void Cdocgia_trasach::OnDtnDatetimechangeDatetimepicker2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: Add your control notification handler code here
	/*CString a;
	GetDlgItemText(IDC_DATETIMEPICKER2, a);
	edit_chontime.SetWindowText(a);*/
	*pResult = 0;
}
void Cdocgia_trasach::OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
BEGIN_MESSAGE_MAP(Cdocgia_trasach, CDialog)
	ON_BN_CLICKED(IDC_DOCGIATRASACH, &Cdocgia_trasach::OnBnClickedDocgiatrasach)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, &Cdocgia_trasach::OnDtnDatetimechangeDatetimepicker1)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER2, &Cdocgia_trasach::OnDtnDatetimechangeDatetimepicker2)
	ON_LBN_SELCHANGE(IDC_LIST1, &Cdocgia_trasach::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// Cdocgia_trasach message handlers


void Cdocgia_trasach::OnBnClickedDocgiatrasach()
{
	// TODO: Add your control notification handler code here
	using namespace std;
	CString str;
	edit_chon.GetWindowText(str);
	CT2CA r(str);
	string chuoi(r);
	string str1 = tok2(chuoi);//cắt lấy tên môn học
	string str2 = str1 + ";" + str1;
	fstream f1, f2, f3, f4;
	f2.open("E:\\data\\khachhang\\luutendangnhap.txt");
	string b;
	getline(f2, b);
	string a = "E:\\data\\khachhangmuonsach\\lichsu_" + b + ".txt";
	string c = "E:\\data\\khachhangmuonsach\\" + b + ".txt";
	f1.open(a,ios::app);
	f2.open(c);
	f4.open("E:\\data\\khachhangmuonsach\\tam.txt", ios::out);
	while (!f2.eof())
	{
		string d;
		getline(f2, d);
		if (d != "")
		{
			f1 << d << endl;
			if (d.compare(str2) != 0)
				f4 << d << endl;
		}
	}
	f1.close();
	f2.close();
	f3.close();
	f4.close();
	const char* s = c.c_str();
	remove(s);
	rename("E:\\data\\khachhangmuonsach\\tam.txt", s);

}







void Cdocgia_trasach::OnLbnSelchangeList1()
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
