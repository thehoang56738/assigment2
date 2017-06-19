// Cdocgiathongbao.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cdocgiathongbao.h"
#include "afxdialogex.h"


// Cdocgiathongbao dialog

IMPLEMENT_DYNAMIC(Cdocgiathongbao, CDialog)

Cdocgiathongbao::Cdocgiathongbao(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DOCGIATHONGBAO, pParent)
{

}

Cdocgiathongbao::~Cdocgiathongbao()
{
}
Cdocgiathongbao::Cdocgiathongbao(CWnd* pParent, CString str)
	: CDialog(IDD_DOCGIATHONGBAO, pParent)
{
	tensys = str;
}

void Cdocgiathongbao::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LISTTHONGBAO, edit_listthongbao);
	DDX_Control(pDX, IDC_LISTTHONGBAO2, edit_listtrasach);
}

BOOL Cdocgiathongbao::OnInitDialog()
{
	CDialog::OnInitDialog();
	using namespace std;
	//edit_listthongbao.InsertString(0, _T("My String1"));
	//edit_listthongbao.InsertString(0, _T("My String2"));
	//edit_listthongbao.InsertString(0, _T("My String3"));
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
		else if ( tentk1.compare(a) ==  0 )
		{
			//lấy ms ten tk ở file mượn sách 
			string tensach1 = tok(c1);
			string soluong1 = tok(c1);//c1ngày tháng
			string str3 = tensach1 + " :: " + soluong1 + " :: " + c1;
			CString str4(str3.c_str());
			edit_listthongbao.InsertString(0, str4);
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
							string tr = tensach2 + " :: " + soluong2 + " :: " + time2 + ":: Bi khoa do qua han tra sach ";
							CString tr1(tr.c_str());
							edit_listtrasach.InsertString(0, tr1);
						}
						else if (thang2 - thang1 > 5)
						{
							string tr =  tensach2 + " :: " + soluong2 + " :: " + time2 + ":: Bi khoa do qua han tra sach ";
							CString tr1(tr.c_str());
							edit_listtrasach.InsertString(0, tr1);
						}
						else
						{
							string tr =  tensach2 + " :: " + soluong2 + " :: " + time2;
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
							string tr =  tensach2 + " :: " + soluong2 + " :: " + time2 + ":: Bi khoa do qua han tra sach ";
							CString tr1(tr.c_str());
							edit_listtrasach.InsertString(0, tr1);
						}
						else
						{
							if (kt_thang == 4 && kt_ngay > 30)
							{
								string tr =  tensach2 + " :: " + soluong2 + " :: " + time2 + ":: Bi khoa do qua han tra sach ";
								CString tr1(tr.c_str());
								edit_listtrasach.InsertString(0, tr1);
							}
							else
							{
								string tr =  tensach2 + " :: " + soluong2 + " :: " + time2;
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
BEGIN_MESSAGE_MAP(Cdocgiathongbao, CDialog)
	ON_LBN_SELCHANGE(IDC_LISTTHONGBAO, &Cdocgiathongbao::OnLbnSelchangeListthongbao)
	ON_BN_CLICKED(IDCANCEL, &Cdocgiathongbao::OnBnClickedCancel)
	ON_LBN_SELCHANGE(IDC_LISTTHONGBAO2, &Cdocgiathongbao::OnLbnSelchangeListthongbao2)
END_MESSAGE_MAP()


// Cdocgiathongbao message handlers


void Cdocgiathongbao::OnLbnSelchangeListthongbao()
{
	// TODO: Add your control notification handler code here
}


void Cdocgiathongbao::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}


void Cdocgiathongbao::OnLbnSelchangeListthongbao2()
{
	// TODO: Add your control notification handler code here
}
