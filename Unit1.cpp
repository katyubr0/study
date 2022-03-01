//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int vMax=0, vPres=0;
std::vector <dishes> dvec;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void ShowPresTxt(){
	Form1->EditName->Text = dvec[vPres].name;
	Form1->EditKitchen->Text = dvec[vPres].kitchen;
	Form1->EditTime->Text = dvec[vPres].time;
	Form1->EditPrice->Text = dvec[vPres].price;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonAddClick(TObject *Sender)
{
	dvec.push_back(dishes());
	if(EditName->Text == ""){
		strcpy(dvec[vMax].name,"Не указано");
	}else{
		strcpy(dvec[vMax].name,AnsiString(EditName->Text).c_str());
	}
	if(EditKitchen->Text == ""){
		strcpy(dvec[vMax].kitchen,"Не указано");
	}else{
		strcpy(dvec[vMax].kitchen,AnsiString(EditKitchen->Text).c_str());
	}
	if(EditTime->Text == ""){
		strcpy(dvec[vMax].time,"Не указано");
	}else{
		strcpy(dvec[vMax].time,AnsiString(EditTime->Text).c_str());
	}
	if(EditName->Text == ""){
		strcpy(dvec[vMax].name,"Не указано");
	}else{
		strcpy(dvec[vMax].price,AnsiString(EditPrice->Text).c_str());
	}
	vPres = vMax;
	vMax++;
	ShowPresTxt();
	LablePage->Caption = vPres + 1;
	LableMax->Caption = vMax;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonBackClick(TObject *Sender)
{
	if(vPres > 0){
		vPres--;
		ShowPresTxt();
		LablePage->Caption = vPres + 1;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonNextClick(TObject *Sender)
{
	if(vPres<vMax-1){
		vPres++;
		ShowPresTxt();
		LablePage->Caption = vPres + 1;
	}
}
//---------------------------------------------------------------------------

