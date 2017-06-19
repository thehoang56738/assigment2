// Clichsutrasach.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Clichsutrasach.h"
#include "afxdialogex.h"


// Clichsutrasach dialog

IMPLEMENT_DYNAMIC(Clichsutrasach, CDialog)

Clichsutrasach::Clichsutrasach(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_LICHSUTRASACH, pParent)
{

}

Clichsutrasach::~Clichsutrasach()
{
}
Clichsutrasach::Clichsutrasach(CWnd* pParent, CString str)
	: CDialog(IDD_LICHSUTRASACH, pParent)
{
	tensys = str;
}
void Clichsutrasach::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, edit_listtrasach);
}

BOOL Clichsutrasach::OnInitDialog()
{
	CDialog::OnInitDialog();
	using namespace std;
	fstream f1, f2, f3;
	f1.open("E:\\data\\lichsu_muonsach.txt");
	//f2.open("E:\\data\\khachhang\\luutendangnhap.txt");
	//f3.open("E:\\data\\lichsu_trasach.txt");
	//Lấy tên đăng nhập
	/*string a;
	getline(f2, a);
	f2.close();*/
	CT2CA ten(tensys);
	string a(ten);
	while (!f1.eof())
	{
		string b1;
		getline(f1, b1);
		string c1 = b1;
		string ms1 = tok(c1);
		string tentk1 = tok(c1);
		if (b1 == "")continue;
		else if (1>0)
		{
			//lấy ms ten tk ở file mượn sách 
			string tensach1 = tok(c1);
			string soluong1 = tok(c1);//c1ngày tháng
			string str3 = tentk1 + " :: " + tensach1 + " :: " + soluong1 + " :: " + c1;
			/*CString str4(str3.c_str());
			edit_listtrasach.InsertString(0, str4);*/
			f3.open("E:\\data\\lichsu_trasach.txt");
			while (!f3.eof())
			{
				string b2;
				getline(f3, b2);
				string c2 = b2;

				//lấy ms tên tk ở file trả sách 
				string ms2 = tok(c2);
				string tentk2 = tok(c2);
				string tensach2 = tok(c2);
				string soluong2 = tok(c2);
				string time2 = c2;//c2 là ngày tháng
				if (ms2.compare(ms1) == 0)
				{
					//lấy ngày tháng năm khi mượn sách
					string t1 = tok_ngay(c1); int thang1 = stoi(t1);
					string n1 = tok_ngay(c1); int ngay1 = stoi(n1);//c1 là năm
					int nam1 = stoi(c1);
					//lấy ngày tháng năm lúc trả sách
					string t2 = tok_ngay(c2); int thang2 = stoi(t2);
					string n2 = tok_ngay(c2); int ngay2 = stoi(n2);//c2 là năm
					int nam2 = stoi(c2);
					if (nam2 == nam1)
					{
						if (thang2 - thang1 == 5 && ngay2 - ngay1 > 3)
						{
							string tr = tentk2 + " :: " + tensach2 + " :: " + soluong2 + " :: " + time2 + ":: Qua han ";
							CString tr1(tr.c_str());
							edit_listtrasach.InsertString(0, tr1);
						}
						else if (thang2 - thang1 > 5)
						{
							string tr = tentk2 + " :: " + tensach2 + " :: " + soluong2 + " :: " + time2 + ":: Qua han ";
							CString tr1(tr.c_str());
							edit_listtrasach.InsertString(0, tr1);
						}
						else
						{
							string tr = tentk2 + " :: " + tensach2 + " :: " + soluong2 + " :: " + time2;
							CString tr1(tr.c_str());
							edit_listtrasach.InsertString(0, tr1);
						}
					}
					else
					{
						int kt_thang = 12 - thang2 + thang1;
						int kt_ngay = ngay2 + ngay1;
						if (kt_thang > 5)
						{
							string tr = tentk2 + " :: " + tensach2 + " :: " + soluong2 + " :: " + time2 + ":: Qua han ";
							CString tr1(tr.c_str());
							edit_listtrasach.InsertString(0, tr1);
						}
						else
						{
							if (kt_thang == 4 && kt_ngay > 30)
							{
								string tr = tentk2 + " :: " + tensach2 + " :: " + soluong2 + " :: " + time2 + ":: Qua han! ";
								CString tr1(tr.c_str());
								edit_listtrasach.InsertString(0, tr1);
							}
							else
							{
								string tr = tentk2 + " :: " + tensach2 + " :: " + soluong2 + " :: " + time2;
								CString tr1(tr.c_str());
								edit_listtrasach.InsertString(0, tr1);
							}
						}
					}
				}
				else
				{
					continue;
				}
			}
			f3.close();
		}
		else continue;
	}
	f1.close();

	return TRUE;
}

BEGIN_MESSAGE_MAP(Clichsutrasach, CDialog)
	ON_LBN_SELCHANGE(IDC_LIST1, &Clichsutrasach::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// Clichsutrasach message handlers


void Clichsutrasach::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
}
