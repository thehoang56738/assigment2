// Cycms.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cycms.h"
#include "afxdialogex.h"
#include "Cmuonsach.h"


// Cycms dialog

IMPLEMENT_DYNAMIC(Cycms, CDialog)

Cycms::Cycms(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_GUIYEUCAU, pParent)
{

}

Cycms::~Cycms()
{
}
Cycms::Cycms(CWnd* pParent, CString str)
	: CDialog(IDD_GUIYEUCAU, pParent)
{
	tensys = str;
}
void Cycms::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_YCMSNOIDUNG, edit_ycmsnoidung);
	DDX_Control(pDX, IDC_YCMSLIST, edit_ycmslist);
	DDX_Control(pDX, IDC_YCMSTENSACH, edit_ycmstensach);
	DDX_Control(pDX, IDC_YCMSGUI, edit_giohang);
}


BEGIN_MESSAGE_MAP(Cycms, CDialog)
	ON_BN_CLICKED(IDC_YCMSTIMKIEM, &Cycms::OnBnClickedYcmstimkiem)
	ON_LBN_SELCHANGE(IDC_YCMSLIST, &Cycms::OnLbnSelchangeYcmslist)
	ON_BN_CLICKED(IDC_YCMSGUI, &Cycms::OnBnClickedYcmsgui)
	ON_BN_CLICKED(IDC_YCMSGIOHANG, &Cycms::OnBnClickedYcmsgiohang)
END_MESSAGE_MAP()


// Cycms message handlers


void Cycms::OnBnClickedYcmstimkiem()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	using namespace std;
	int bienphu = 0;
	// reset lại listbox
	edit_ycmslist.ResetContent();
	ASSERT(edit_ycmslist.GetCount() == 0);

	CString str1;
	edit_ycmsnoidung.GetWindowText(str1);
	CT2CA a(str1);
	string tens(a);
	string tensach = exchange(tens);
	fstream f1, f2, f3;
	f1.open("E:\\data\\tensach.txt");
	f3.open("E:\\data\\out.txt", ios::out);
	string hienthi = "";
	while (!f1.eof())
	{
		string ab;
		getline(f1, ab);
		string cd = exchange(ab);
		if (ab == "") continue;
		if (tensach == " ") continue;
		else
		{
			int timtensach = cd.find(tensach);
			if (timtensach == -1) // tìm không giống
			{
				string cd = "E:\\data\\thuvien\\" + ab + ".txt";
				f2.open(cd, ios::in);
				while (!f2.eof())
				{
					string str;
					getline(f2, str);
					string str3 = exchange(str);
					int timnoidung = str3.find(tensach);
					if (str == "") continue;
					else
					{
						if (timnoidung == -1) continue;
						else
						{
							//hienthi += ab + "\r\n";
							CString xuat(ab.c_str());
							edit_ycmslist.AddString(xuat);
							f3 << ab << endl;
							bienphu++;
							break;
						}
					}

				}
				f2.close();
			}
			else// nếu tên sách giống tên tìm thì gán biến và thoát ra
			{
				//hienthi += ab + "\r\n";
				CString xuat(ab.c_str());
				edit_ycmslist.AddString(xuat);
				f3 << ab << endl;
				bienphu++;
			}
		}
	}
	if (bienphu == 0)
	{
		edit_ycmslist.AddString(_T("Không tìm thấy dữ liệu..."));
	}
	f3.close();
	remove("E:\\data\\out.txt");
	UpdateData(FALSE);
	f1.close();
}


void Cycms::OnLbnSelchangeYcmslist()
{
	// TODO: Add your control notification handler code here
	//Lấy phần tử đang được chọn
	int a = edit_ycmslist.GetCurSel();
	if (a < 0) return;
	CString b;
	edit_ycmslist.GetText(a, b);
	edit_ycmstensach.SetWindowText(b);
	//Update từ m_txtEdit lên Edit Control
	UpdateData(FALSE);
}

void Cycms::OnBnClickedYcmsgiohang()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	using namespace std;
	CString str1;
	edit_ycmstensach.GetWindowText(str1);
	CT2CA zx(str1);
	string tensach(zx);
	if (tensach == "") return;
	fstream f1,f2;
	f1.open("E:\\data\\giohang.txt");
	f2.open("E:\\data\\tam.txt",ios::app);
	//f1 << tensach;
	int i = 0;
	while (!f1.eof())
	{
		string ab, cd;
		getline(f1, ab);
		cd = ab;
		if (cd == "")
		{
			if (i == 0) i++;
			continue;
		}
		else
		{
			string d = tok(cd);
			if (d.compare(tensach) == 0)
			{
				
				i = stoi(cd);
				i++;
				//f2 << tensach + ";" + to_string(i) << endl;
			}
			else f2 << ab << endl;
		}
	}
	f2 << tensach + ";" + to_string(i) << endl;

	f1.close();
	f2.close();
	remove("E:\\data\\giohang.txt");
	rename("E:\\data\\tam.txt", "E:\\data\\giohang.txt");
}
void Cycms::OnBnClickedYcmsgui()
{
	// TODO: Add your control notification handler code here
	Cmuonsach th(NULL, tensys); //
	th.DoModal();
}