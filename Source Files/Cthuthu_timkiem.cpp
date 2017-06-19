// Cthuthu_timkiem.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cthuthu_timkiem.h"
#include "afxdialogex.h"
#include "SecondDlg.h"

// Cthuthu_timkiem dialog

IMPLEMENT_DYNAMIC(Cthuthu_timkiem, CDialog)

Cthuthu_timkiem::Cthuthu_timkiem(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_THUTHUTIMKIEM, pParent)
{

}

Cthuthu_timkiem::~Cthuthu_timkiem()
{
}
Cthuthu_timkiem::Cthuthu_timkiem(CWnd* pParent, CString str)
	: CDialog(IDD_THUTHUTIMKIEM, pParent)
{
	tensys = str;
}
void Cthuthu_timkiem::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit_timkiemsach);
	DDX_Control(pDX, IDC_LISTTIMSACH, edit_listtimsach);
	DDX_Control(pDX, IDC_EDIT2, edit_noidungsach);
}


BEGIN_MESSAGE_MAP(Cthuthu_timkiem, CDialog)
	ON_EN_CHANGE(IDC_EDIT1, &Cthuthu_timkiem::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_TIMKIEMSACH, &Cthuthu_timkiem::OnBnClickedTimkiemsach)
	ON_LBN_SELCHANGE(IDC_LISTTIMSACH, &Cthuthu_timkiem::OnLbnSelchangeListtimsach)
END_MESSAGE_MAP()


// Cthuthu_timkiem message handlers


void Cthuthu_timkiem::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void Cthuthu_timkiem::OnBnClickedTimkiemsach()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	using namespace std;
	int bienphu = 0;
	// reset lại listbox
	edit_listtimsach.ResetContent();
	ASSERT(edit_listtimsach.GetCount() == 0);

	CString str1;
	edit_timkiemsach.GetWindowText(str1);
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
							edit_listtimsach.AddString(xuat);
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
				edit_listtimsach.AddString(xuat);
				f3 << ab << endl;
				bienphu++;
			}
		}
	}
	if (bienphu == 0)
	{
		edit_listtimsach.AddString(_T("Không tìm thấy dữ liệu..."));
	}
	//f3 << bienphu;
	f3.close();
	/*f3.open("E:\\out.txt", ios::in);
	while (!f3.eof())
	{
		string str2;
		getline(f3, str2);
		if (str2 != "")
		{
			CString g(str2.c_str());
			edit_listtimsach.AddString(g);
		}
	}
	f3.close();*/
	remove("E:\\data\\out.txt");
	/*for (int i = 0; i < edit_listtimsach.GetCount(); i++)
	{
		edit_listtimsach.DeleteString(2*i);
	}*/
	/*CString xuat(hienthi.c_str());
	edit_listtimsach.AddString(xuat);*/
	/*for (int i = 0; i < bienphu; i++)
	{
		edit_listtimsach.DeleteString(i);
	}*/
	//edit_listtimsach.DeleteString(1);
	UpdateData(FALSE);
	
	f1.close();
}

void Cthuthu_timkiem::OnLbnSelchangeListtimsach()
{
	// TODO: Add your control notification handler code here
	using namespace std;
	int a = edit_listtimsach.GetCurSel();
	if (a < 0) return;
	CString b;
	edit_listtimsach.GetText(a, b);
	CT2CA c(b);
	string tensach(c);
	fstream f1;
	string duongdan = "E:\\data\\thuvien\\" + tensach + ".txt";
	f1.open(duongdan);
	string data;
	int dem = 0;
	while (!f1.eof())
	{
		string str;
		getline(f1, str);
		if (str != "" && dem < 8)
		{
			data += str + "\r\n";
			dem++;
		}
	}
	data += "...";
	CString z(data.c_str());
	edit_noidungsach.SetWindowText(z);
}
