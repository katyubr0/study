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
	ButtonNext->Visible = false;
	ButtonBack->Visible = false;
	vPres = vMax;
	vMax++;
	LablePage->Caption = vPres + 1;
	LableMax->Caption = vMax;
	Form1->EditName->Text = "";
	Form1->EditKitchen->Text = "";
	Form1->EditTime->Text = "";
	Form1->EditPrice->Text = "";
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

void __fastcall TForm1::ButtonSaveClick(TObject *Sender)
{
		if (SaveDialog1->Execute()){
		FILE *f = fopen(AnsiString(SaveDialog1->FileName).c_str(), "wb");
		fwrite(&dvec[0],sizeof(dishes),vMax,f);
		fclose(f);
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonOpenClick(TObject *Sender)
{
	if(OpenDialog1->Execute()){
		ButtonAdd->Visible = true;
		FILE *f = fopen(AnsiString(OpenDialog1->FileName).c_str(), "rb");
		for(int i=0; i<dvec.max_size(); i++){
			dishes s;
			fread(&s,sizeof(dishes),1,f);
			if(feof(f)) break;
			dvec.push_back(s);
		}
		fclose(f);
		vMax=dvec.size();
		vPres=0;
		ShowPresTxt();
		LablePage->Caption = vPres + 1;
		LableMax->Caption = vMax;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonCreateClick(TObject *Sender)
{
	ButtonAdd->Visible = true;
	ButtonAccept->Visible = true;
	EditName->Enabled = true;
	EditKitchen->Enabled = true;
	EditTime->Enabled = true;
	EditPrice->Enabled = true;
	vMax = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonAcceptClick(TObject *Sender)
{
	ButtonSave->Visible = True;
	ButtonBack->Visible = True;
	ButtonNext->Visible = True;
	dvec.push_back(dishes());
	if(EditName->Text == ""){
		strcpy(dvec[vPres].name,"�� �������");
	}else{
		strcpy(dvec[vPres].name,AnsiString(EditName->Text).c_str());
	}
	if(EditKitchen->Text == ""){
		strcpy(dvec[vPres].kitchen,"�� �������");
	}else{
		strcpy(dvec[vPres].kitchen,AnsiString(EditKitchen->Text).c_str());
	}
	if(EditTime->Text == ""){
		strcpy(dvec[vPres].time,"�� �������");
	}else{
		strcpy(dvec[vPres].time,AnsiString(EditTime->Text).c_str());
	}
	if(EditName->Text == ""){
		strcpy(dvec[vPres].price,"�� �������");
	}else{
		strcpy(dvec[vPres].price,AnsiString(EditPrice->Text).c_str());
	}
	LableMax->Caption = vMax;
	LablePage->Caption = vPres+1;
}
//---------------------------------------------------------------------------

