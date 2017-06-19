// Cthemvao.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cthemvao.h"
#include "afxdialogex.h"

// Cthemvao dialog

IMPLEMENT_DYNAMIC(Cthemvao, CDialog)

Cthemvao::Cthemvao(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_THEMVAO, pParent)
{

}

Cthemvao::~Cthemvao()
{
}
void Cthemvao::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NOIDUNGSACH, edit_themsach);
	DDX_Control(pDX, IDC_LUUY, edit_luuy);
	//DDX_Control(pDX, IDC_LISTTV, edit_luuy1);
	//DDX_Control(pDX, IDC_LIST_TV, edit_luuy2);
	DDX_Control(pDX, IDC_LIST69, edit_list69);
}
BOOL Cthemvao::OnInitDialog()
{
	CDialog::OnInitDialog();
//	using namespace std;
//	
//	edit_list69.AddString(_T("Nhập tên sách vô khung trên và nhấn nút Cập Nhật để nhập nội dung của sách."));
//	edit_list69.AddString(_T("Khi nhập xong phải Save để không bị mất dữ liệu vừa nhập."));
//	//z.Format(_T("%f"), data);
//
//	// TODO:  Add extra initialization here
//	//AfxMessageBox(_filename.GetBuffer());
//	
//	//edit_sys_tendangnhap.SetWindowText(tensys);
//
	return TRUE;
}



BEGIN_MESSAGE_MAP(Cthemvao, CDialog)
	ON_EN_CHANGE(IDC_NOIDUNGSACH, &Cthemvao::OnEnChangeNoidungsach)
	ON_BN_CLICKED(IDC_BUTTON1, &Cthemvao::OnBnClickedButton1)
	ON_LBN_SELCHANGE(IDC_LIST69, &Cthemvao::OnLbnSelchangeList69)
END_MESSAGE_MAP()


// Cthemvao message handlers


void Cthemvao::OnEnChangeNoidungsach()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO:  Add your control notification handler code here.
}


void Cthemvao::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	using namespace std;
	CString str1;
	edit_themsach.GetWindowText(str1);
	CT2CA a(str1);
	string tens(a); 
	string tensach = inhoa(tens);
	if (tensach == "" || tens == " ") {}
	else
	{
		//string tensach = inhoa(tens);
		string b = "E:\\thuvien\\" + tensach + ".txt";
		fstream f1, f2;
		f1.open(b, ios::app);
		f2.open("E:\\tensach.txt", ios::in);
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
		f2.open("E:\\tensach.txt", ios::app);
		if (check == 0)
			f2 << tensach << endl;
		f1.close();
	}
	
}


void Cthemvao::OnLbnSelchangeList69()
{
	// TODO: Add your control notification handler code here
}
