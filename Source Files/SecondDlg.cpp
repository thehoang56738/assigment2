// SecondDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "SecondDlg.h"
#include "afxdialogex.h"

#include "Thongbaodangki.h"
#include "Cthongbaosaiid.h"



std::fstream fs1;


// CSecondDlg dialog

IMPLEMENT_DYNAMIC(CSecondDlg, CDialog)

CSecondDlg::CSecondDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_SECOND_DLG, pParent)
	, edit_radio1(0)
	, edit_radio2(0)
	, edit_radio3(0)
{

}

CSecondDlg::~CSecondDlg()
{

}

void CSecondDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON2, edit_dangki1);
	DDX_Control(pDX, IDC_EDIT1, edit_tendangnhap);
	DDX_Control(pDX, IDC_EDIT2, edit_matkhau);
	DDX_Control(pDX, IDC_EDIT3, edit_xacnhanmatkhau);
	DDX_Control(pDX, IDC_MSSV, edit_MSSV);
	DDX_Check(pDX, IDC_RADIO1, edit_radio1);
	DDX_Check(pDX, IDC_RADIO2, edit_radio2);
	DDX_Check(pDX, IDC_RADIO3, edit_radio3);
}
BOOL CSecondDlg::OnInitDialog()
{
	//CDialogEx::OnInitDialog();

	//// Set the icon for this dialog.  The framework does this automatically
	////  when the application's main window is not a dialog
	//SetIcon(m_hIcon, TRUE);			// Set big icon
	//SetIcon(m_hIcon, FALSE);		// Set small icon

	//								// TODO: Add extra initialization here

	edit_radio1 = 1;
	edit_radio2 = 0;
	edit_radio3 = 0;
	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}



BEGIN_MESSAGE_MAP(CSecondDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON2, &CSecondDlg::OnBnClickDangki)
	//ON_BN_CLICKED(IDC_RADIO4, &CSecondDlg::OnBnClickedRadio4)
END_MESSAGE_MAP()

using namespace std;
void CSecondDlg::OnBnClickDangki()
{

	UpdateData(TRUE);
	CString  str_1, str_2,str_3;
	edit_MSSV.GetWindowText(str_3);
	CT2CA fffs(str_3);
	std::string MSSV(fffs);
	//using namespace std;
	fstream ff001;
	ff001.open("E:\\data\\ttkhachhang.txt", ios::in);
	string line;
	int check = 0;
	string d_maso;
	string c;
	while (!ff001.eof())
	{
		getline(ff001, line);
		d_maso = tok(line); //  la maso
		c = tok(line); // la ID
		if (c == MSSV)
		{
			check = 1;
			break;
		}
	}
	ff001.close();

	fstream ff002;
	ff002.open("E:\\data\\tttk.txt", ios::in);
	string line2;
	int dem = 1;
	while (!ff002.eof())
	{
		getline(ff002, line2);
		string fdf1 = tok(line2);
		if (fdf1 == d_maso) dem++;
		
	}
	ff002.close();
	if (check == 1)
	{
		edit_tendangnhap.GetWindowText(str_1);
		CT2CA ps(str_1);
		std::string tendangnhap(ps);

		edit_matkhau.GetWindowText(str_2);
		CT2CA ps1(str_2);

		std::string matkhau(ps1);
		fs1.open("E:\\data\\tttk.txt", std::ios::app);
		fs1 << d_maso << ";" << dem << ";1;" << tendangnhap << ";" << matkhau << endl;
		fs1.close();
		
		string name = "E:\\data\\khachhang\\" + tendangnhap + ".txt";
		fstream ff11;
		ff11.open(name, ios::app);
		ff11.close();
		// fai tao them 1 file trong nay , neu ko la loi~

		string name2 = "E:\\data\\khachhangmuonsach\\" + tendangnhap + ".txt";
		fstream ff112;
		ff112.open(name2, ios::app);
		ff112.close();


		UpdateData(FALSE);
		CThongbaodangki dlg1;// thong bao thanh cong
		dlg1.DoModal();

	}
	else
	{
		Cthongbaosaiid dlg11; // thong bao sai MSSV
		dlg11.DoModal();
	}

}
