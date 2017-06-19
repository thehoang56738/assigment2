// Cdocgia_dmk.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cdocgia_dmk.h"
#include "afxdialogex.h"


// Cdocgia_dmk dialog

IMPLEMENT_DYNAMIC(Cdocgia_dmk, CDialog)

Cdocgia_dmk::Cdocgia_dmk(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DOCGIA_DMK, pParent)
{

}

Cdocgia_dmk::~Cdocgia_dmk()
{
}
Cdocgia_dmk::Cdocgia_dmk(CWnd* pParent, CString str)
	: CDialog(IDD_DOCGIA_DMK, pParent)
{
	tensys = str;
}
void Cdocgia_dmk::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, edit_mk_moi);
	DDX_Control(pDX, IDC_EDIT3, edit_mk_moi2);
	DDX_Control(pDX, IDC_EDIT4, edit_mk_nhaplai);
	DDX_Control(pDX, IDC_TENTK, edit_docgia_dmk);
	DDX_Control(pDX, IDC_EDIT5, edit_thongbao);
}
BOOL Cdocgia_dmk::OnInitDialog()
{
	CDialog::OnInitDialog();
	/*std::string a = "kakakakak";
	CString ff(a.c_str());*/
	edit_docgia_dmk.SetWindowText(tensys);
	return TRUE;
}

BEGIN_MESSAGE_MAP(Cdocgia_dmk, CDialog)
	ON_BN_CLICKED(IDOK, &Cdocgia_dmk::OnBnClickedOk)
END_MESSAGE_MAP()


// Cdocgia_dmk message handlers


void Cdocgia_dmk::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialog::OnOK();
	using namespace std;
	UpdateData(TRUE);

	CString xau1;
	edit_mk_moi.GetWindowText(xau1);
	CT2CA x1(xau1);
	std::string mkcu(x1);

	CString xau2;
	edit_mk_moi2.GetWindowText(xau2);
	CT2CA x2(xau2);
	std::string mkmoi(x2);

	CString xau3;
	edit_mk_nhaplai.GetWindowText(xau3);
	CT2CA x3(xau3);
	std::string mkmoinl(x3);

	CString tendn123;
	edit_docgia_dmk.GetWindowText(tendn123);
	CT2CA ss(tendn123);
	string tendangnhap(ss);

	//UpdateData(FALSE);	
	
	//using namespace std;
	fstream file1;
	file1.open("E:\\data\\tttk.txt", ios::in);
	string line, data = "";
	string phu;
	string ID, tt, yn, tend, mk;
	while (!file1.eof())
	{
		getline(file1, line);
		phu = line;
		ID = tok(phu); // ID ma so tai khoan
		tt = tok(phu); //
		yn = tok(phu);
		tend = tok(phu);
		if (tend == tendangnhap)
		{
			if (phu.compare(mkcu)==0)
			{
				data = ID + ";" + tt + ";" + yn + ";" + tendangnhap + ";" + mkmoi + "\n";
			}
			else 
			{
				edit_thongbao.SetWindowText(_T("Sai mật khẩu cũ!"));
				return;
			}
		}
		else data = data + line + "\n";
	}
	if (mkmoi.compare(mkmoinl) != 0)
	{
		edit_thongbao.SetWindowText(_T("Hai mật khẩu không trùng khớp!"));
		return;
	}
	else edit_thongbao.SetWindowText(_T(""));
	file1.close();
	fstream ff1;
	ff1.open("E:\\data\\tttk.txt", ios::out);
	ff1 << data;
	ff1.close();
	edit_thongbao.SetWindowText(_T("Cập Nhập Mật Khẩu Mới Thành Công!"));
}
