//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
int i;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void ShowPresTxt(){
	Form1->EditName->Text = dvec[vPres].name;
	Form1->EditKitchen->Text = dvec[vPres].kitchen;
	Form1->EditTime->Text = dvec[vPres].time;
	Form1->EditPrice->Text = dvec[vPres].price;
	Form1->ButtonHave->Checked = dvec[vPres].have;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonSearchClick(TObject *Sender)
{
	dishes d;
	std::vector<dishes>::iterator p;
	if (EditSearchName->Text != "") {
		strcpy(d.name, AnsiString(Form2->EditSearchName->Text).c_str());
	}
	if (EditSearchKitchen->Text != "") {
		strcpy(d.kitchen, AnsiString(Form2->EditSearchKitchen->Text).c_str());
	}
	if (EditSearchTime->Text != "") {
		d.time = Form2->EditSearchTime->Text.ToInt();
	}else{
		d.time = 0;
	}
	if (EditSearchPrice->Text != "") {
		d.price = Form2->EditSearchPrice->Text.ToInt();
	}else{
		d.price = 0;
	}
	search:
	p=std::find(dvec.begin()+i,dvec.end(),d);
	if(vPres == p - dvec.begin()){
		i++;
		goto search;	
	}
	vPres = p - dvec.begin();
	if(vPres<vMax){
		ShowPresTxt();
		Form1->LablePage->Caption = vPres+1;
	}else{
		vPres = 0;
		Form1->LablePage->Caption = 0;
		ShowPresTxt();
		MessageBox(0,L"По поиску ничего не найдено!", L"", MB_OK);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
	i = 0;	
}
//---------------------------------------------------------------------------

