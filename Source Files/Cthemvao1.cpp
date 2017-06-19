// Cthemvao1.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cthemvao1.h"
#include "afxdialogex.h"


// Cthemvao1 dialog

IMPLEMENT_DYNAMIC(Cthemvao1, CDialogEx)

Cthemvao1::Cthemvao1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_THEMVAO1, pParent)
{

}

Cthemvao1::~Cthemvao1()
{
}
Cthemvao1::Cthemvao1(CWnd* pParent, CString str)
	: CDialogEx(IDD_THEMVAO1, pParent)
{
	tensys = str;
}
void Cthemvao1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_THEMVAOTENSACH, edit_tensach1);
	DDX_Control(pDX, IDC_LISTLUUY, edit_listluuy);
	DDX_Control(pDX, IDC_THUTHU_LISTTENSACH, edit_thuthu_listsach);
}
BOOL Cthemvao1::OnInitDialog()
{
	CDialog::OnInitDialog();
	using namespace std;
		
	edit_listluuy.AddString(_T("Nhập tên sách vô khung trên và nhấn nút ( Cập Nhật ) để nhập nội dung của sách."));
	edit_listluuy.AddString(_T("Khi nhập xong phải Save để không bị mất dữ liệu vừa nhập."));

	fstream f1;
	f1.open("E:\\data\\tensach.txt");
	while (!f1.eof())
	{
		string a;
		getline(f1, a);
		if (a != "")
		{
			CString b(a.c_str());
			edit_thuthu_listsach.AddString(b);
		}
		else continue;
	}
		//z.Format(_T("%f"), data);
	
		// TODO:  Add extra initialization here
		//AfxMessageBox(_filename.GetBuffer());
		
	//	//edit_sys_tendangnhap.SetWindowText(tensys);
	//
	return TRUE;
}

BEGIN_MESSAGE_MAP(Cthemvao1, CDialogEx)
	ON_BN_CLICKED(IDC_CAPNHATSACH, &Cthemvao1::OnBnClickedCapnhatsach)
	ON_LBN_SELCHANGE(IDC_THUTHU_LISTTENSACH, &Cthemvao1::OnLbnSelchangeThuthuListtensach)
END_MESSAGE_MAP()


// Cthemvao1 message handlers


void Cthemvao1::OnBnClickedCapnhatsach()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	using namespace std;
	CString str1;
	edit_tensach1.GetWindowText(str1);
	CT2CA a(str1);
	string tens(a);
	string tensach = inhoa(tens);
	if (tensach == "" || tens == " ")
	{
		/*edit_listluuy.ResetContent();
		ASSERT(edit_listluuy.GetCount() == 0);*/
		edit_listluuy.AddString(_T("Vui lòng nhập tên sách!"));

	}
	else
	{
		//string tensach = inhoa(tens);
		string b = "E:\\data\\thuvien\\" + tensach + ".txt";
		fstream f1, f2;
		f1.open(b, ios::app);
		f2.open("E:\\data\\tensach.txt", ios::in);
		//CString z(data.c_str());
		CString file(b.c_str());
		//mở <tên sách>.txt lên để soạn
		if (::ShellExecute(NULL, _T("open"), file/*_T("E:\\khachhang\\kunam123.txt"*/,
			NULL, NULL, SW_SHOW) > (HINSTANCE)32)
		{
			::Sleep(666); // some "magic" time to wait
			HWND hWndMain = ::FindWindow(_T("Notepad"), NULL);
			// HWND hWndMain = ::GetForegroundWindow();
			// ...
		}
		int check = 0;
		while (!f2.eof())
		{
			string ab;
			getline(f2, ab);
			if (ab.compare(tensach) == 0)
			{
				check = 1;
				break;
			}
		}
		f2.close();
		f2.open("E:\\data\\tensach.txt", ios::app);
		if (check == 0)
			f2 << tensach << endl;
		f1.close();
	}

}


void Cthemvao1::OnLbnSelchangeThuthuListtensach()
{
	// TODO: Add your control notification handler code here
}
