// Cqlnd.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cqlnd.h"
#include "afxdialogex.h"
#include "SecondDlg.h"
#include "Cqlnd_dmk.h"

#include "Cqlnd_tk.h"
#include "Cqlnd_xoa.h"

#include "Cqlnd_mktk.h"

#include "Cqlnd_tvt.h"
#include "Cqlnd_dstv.h"

//#include "Cbienphu.h"

// Cqlnd dialog

IMPLEMENT_DYNAMIC(Cqlnd, CDialog)
//khởi tạo truyen tham so,
Cqlnd::Cqlnd(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_QLND, pParent)
{

}
Cqlnd::Cqlnd(CWnd* pParent, CString str)
	: CDialog(IDD_QLND, pParent)
{
	tensys = str;
}


Cqlnd::~Cqlnd()
{
}

void Cqlnd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_USER, edit_sys_tendangnhap);
	DDX_Control(pDX, IDC_THONGBAOQLND, edit_THONGBAOQLND);
}
// khởi tạo mặc dinh chay trc chuong trinh
BOOL Cqlnd::OnInitDialog() 
{
	CDialog::OnInitDialog();
	using namespace std;
	// doc lai du lieu tai day
	fstream ff1, ff2;
	ff1.open("E:\\data\\lichsu_qlnd.txt", ios::in);
	string line1, line2;
	int check12 = 0;
	while (!ff1.eof())
	{
		getline(ff1, line1);
		if (line1 != "")
		{
			check12 = 1;
			string data = "";
			ff2.open("E:\\data\\list_themtaikhoan.txt", ios::in);
			while (!ff2.eof())
			{
				getline(ff2, line2);
				if (line2 == line1) continue;
				else data = data + line2 + "\n";
			}
			ff2.close();
			ff2.open("E:\\data\\list_themtaikhoan.txt", ios::out);
			ff2 << data;
			ff2.close();
		}
	}
	ff1.close();
	if (check12 == 1)
	{
		ff1.open("E:\\data\\lichsu_qlnd.txt", ios::out);
		ff1 << "";
		ff1.close();
	}
	//
	fstream f1,f2;
	/*CT2CA d(tensys);
	string abc(d);*/
	string tenfile = "E:\\data\\list_themtaikhoan.txt";
	f1.open(tenfile, ios::in);
	string data = "", line;
	while (!f1.eof())
	{
		getline(f1, line);
		if (line != "")
		{
			line = line + "\r\n";
			data = data +  line ;
		}
	}
	f1.close();
	CString z(data.c_str());
	edit_THONGBAOQLND.SetWindowText(z);
	edit_sys_tendangnhap.SetWindowText(tensys);
	
	return TRUE;
}

//BOOL Cqlnd::showaccount()
//{
//		CString str_1;
//		str_1.Format(_T("%f"),tensys);
//		edit_sys_tendangnhap.SetWindowText(str_1);
//		UpdateData(FALSE);
//		return TRUE;
//
//}


BEGIN_MESSAGE_MAP(Cqlnd, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &Cqlnd::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_QLND_DMK, &Cqlnd::OnBnClickedQlndDmk)
	ON_EN_CHANGE(IDC_EDIT1, &Cqlnd::OnEnChangeEdit1)

	ON_BN_CLICKED(IDC_QLND_TK, &Cqlnd::OnBnClickedQlndTk)
	ON_BN_CLICKED(IDC_QLND_MKTK, &Cqlnd::OnBnClickedQlndMktk)
	ON_BN_CLICKED(IDC_QLND_XOA, &Cqlnd::OnBnClickedQlndXoa)
	ON_BN_CLICKED(IDC_QLND_TVT_QLND, &Cqlnd::OnBnClickedQlndTvtQlnd)
	ON_BN_CLICKED(IDC_QLND_XOA2, &Cqlnd::OnBnClickedQlndXoa2)
	ON_BN_CLICKED(IDOK, &Cqlnd::OnBnClickedOk)
	ON_EN_CHANGE(IDC_THONGBAOQLND, &Cqlnd::OnEnChangeThongbaoqlnd)
END_MESSAGE_MAP()


// Cqlnd message handlers


void Cqlnd::OnBnClickedButton1()
{
	
}


void Cqlnd::OnBnClickedQlndDmk()
{
	
	Cqlnd_dmk dg1;
	dg1.DoModal();
}


void Cqlnd::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}




void Cqlnd::OnBnClickedQlndTk()
{
	Cqlnd_tk dg123;
	dg123.DoModal();
}


void Cqlnd::OnBnClickedQlndMktk()
{
	Cqlnd_mktk mk1;
	mk1.DoModal();

}


void Cqlnd::OnBnClickedQlndXoa()
{
	Cqlnd_xoa xoa12;
	xoa12.DoModal();
}


void Cqlnd::OnBnClickedQlndTvtQlnd()
{
	Cqlnd_tvt tvt1;
	tvt1.DoModal();
}


void Cqlnd::OnBnClickedQlndXoa2()
{
	Cqlnd_dstv tv1;
	tv1.DoModal();
}


void Cqlnd::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}


void Cqlnd::OnEnChangeThongbaoqlnd()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
