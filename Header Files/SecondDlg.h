#pragma once
#include "afxwin.h"
#include <iostream>
#include <fstream>
#include <string>

static std::string tok(std::string &a)
{
	std::string b;
	int z = a.size();
	for (int i = 0; i < z; i++)
	{
		int t = i;
		if (a[i] == ';')
		{
			a = a.erase(0, i + 1);
			break;
		}
		else  b.push_back(a[i]);
	}
	return b;
	
}
static std::string tok_ngay(std::string &a)
{
	std::string b;
	int z = a.size();
	for (int i = 0; i < z; i++)
	{
		int t = i;
		if (a[i] == '/')
		{
			a = a.erase(0, i + 1);
			break;
		}
		else  b.push_back(a[i]);
	}
	return b;

}
static std::string tok2(std::string &a)
{
	std::string b;
	int z = a.size();
	for (int i = 0; i < z; i++)
	{
		int t = i;
		if (a[i] == ':')
		{
			a = a.erase(0, i + 3);
			break;
		}
		else b.push_back(a[i]);
	}
	b.erase(b.size() - 1, b.size());
	return b;
}
static std::string exchange(std::string a)
{
	std::string d;
	const char* b = a.c_str();
	//int kq = stricmp(a, b);
	int z = a.size();
	for (int i = 0; i < z; i++)
	{
		if (b[i] >= 'A'&&b[i] <= 'Z')
		{
			int f = b[i];
			f += 32;
			const char c = f;
			d.push_back(c);
		}
		else d.push_back(b[i]);
	}
	return d;
}
static std::string inhoa(std::string a)
{
	std::string d;
	int k = a.size();
	const char* b = a.c_str();
	//int kq = stricmp(a, b);
	for (int i = 0; i < k; i++)
	{
		if (b[i] == ' ' || i == 0)
		{
			if (b[i + 1] != ' ')
			{
				if (b[i + 1] >= 'a' && b[i + 1] <= 'z')
				{
					if (i == 0)
					{
						if (b[i] >= 'a' && b[i] <= 'z')
						{
							int f = b[i];
							f -= 32;
							const char c = f;
							//d.push_back(b[i]);
							d.push_back(c);
						}
						else d.push_back(b[i]);
					}
					else
					{
						int f = b[i + 1];
						f -= 32;
						const char c = f;
						d.push_back(b[i]);
						d.push_back(c);
						i++;
					}
				}
				else if (i == 0) d.push_back(b[i]);
				else
				{
					d.push_back(' ');
					continue;
				}
			}
		}
		else d.push_back(b[i]);
	}
	if (d[0] == ' ')
	{
		d.erase(0, 1);
	}
	return d;
}
// CSecondDlg dialog

class CSecondDlg : public CDialog
{
	DECLARE_DYNAMIC(CSecondDlg)

public:
	CSecondDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSecondDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SECOND_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog(); //  ham khoi tao ban dau

	DECLARE_MESSAGE_MAP()
public:


	/*afx_msg void OnBnClickedButton2();*/
	afx_msg void OnBnClickDangki();
protected:
	CButton edit_dangki1;
	CEdit edit_tendangnhap;
	CEdit edit_matkhau;
	CEdit edit_xacnhanmatkhau;
	CEdit edit_MSSV;
	int edit_radio1;
	int edit_radio2;
	int edit_radio3;
};
