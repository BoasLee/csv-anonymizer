
// TDE GUIDlg.h : header file
//

#pragma once
using namespace std;
#include "afxwin.h"
#include <fstream>
#include <string>



// CTDEGUIDlg dialog
class CTDEGUIDlg : public CDialogEx
{
// Construction
public:
	CTDEGUIDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TDEGUI_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit MyFilePath_TextBox;
	CButton FilePathSelection_Button;
	afx_msg void OnBnClickedFilePathSelection_Button();


	// My Defined Variables / Functions
	protected:
	public:
	// Variables	
	int NumberofColumns;
	CString MyFilePathIn;	
	CString MyFilePathOut;
	CCheckListBox MyCheckList;

	CEdit FullFilePath_TextBox;
	// Functions
	int GetNumberofColumns(string);
	void PopulateCheckBox(CString Filepath);
	string  DeleteFirstWord(string &a);
	afx_msg void OnBnClickedOk();
	bool * ReadCheckBox(); // Programmer aka the amazing BOAS must be smart and delete array after use.
	void ProcessFile();
};