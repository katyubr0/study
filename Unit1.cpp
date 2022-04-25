//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int vMax=0, vPres=0;
std::vector <dishes> dvec;
std::vector<TButton *> buttonList;
std::vector <TMenuItem *> menuList;
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
	Form1->ButtonHave->Checked = dvec[vPres].have;

}
//---------------------------------------------------------------------------
void EditEnabled(bool bol){
	Form1->EditName->Enabled = bol;
	Form1->EditKitchen->Enabled = bol;
	Form1->EditTime->Enabled = bol;
	Form1->EditPrice->Enabled = bol;
	Form1->ButtonHave->Enabled = bol;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonAddClick(TObject *Sender)
{
	ButtonNext->Visible = false;
	ButtonBack->Visible = false;
	ButtonAdd->Visible = false;
	ButtonDelete->Visible = false;
	ButtonAccept->Visible = true;
	MenuSearch->Visible = false;
	EditEnabled(true);

	vPres = vMax;
	vMax++;

	LablePage->Caption = vPres + 1;
	LableMax->Caption = vMax;

	EditName->Text = "";
	EditKitchen->Text = "";
	EditTime->Text = "";
	EditPrice->Text = "";
	ButtonHave->Checked = false;
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

void __fastcall TForm1::ButtonAcceptClick(TObject *Sender)
{

	dvec.push_back(dishes());
	if(EditName->Text == "" || EditTime->Text == "" || EditPrice->Text == ""){
		MessageBox(0,L"Не заполнено обязательное поле!", L"Ошибка!", MB_OK + MB_ICONWARNING);
	}else{
		strcpy(dvec[vPres].name,AnsiString(EditName->Text).c_str());
		dvec[vPres].time = EditTime->Text.ToInt();
		dvec[vPres].price = EditPrice->Text.ToInt();
		dvec[vPres].have = ButtonHave->Checked;

		if(vMax>1){
			ButtonBack->Visible = true;
			ButtonNext->Visible = true;
			MenuSearch->Visible = true;
		}
		ButtonAdd->Visible = true;
		MenuSave->Visible = true;
		MenuClose->Visible = true;
		MenuEdit->Visible = true;
		ButtonDelete->Visible = true;
		ButtonAccept->Visible = false;
		LableMax->Caption = vMax;
		LablePage->Caption = vPres+1;
		EditEnabled(false);
	}
	if(EditKitchen->Text == ""){
		strcpy(dvec[vPres].kitchen,"Не указано");
		EditKitchen->Text = "Не указано";
	}else{
		strcpy(dvec[vPres].kitchen,AnsiString(EditKitchen->Text).c_str());
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuOpenClick(TObject *Sender)
{
	if(OpenDialog1->Execute()){
		FILE *f = fopen(AnsiString(OpenDialog1->FileName).c_str(), "rb");
		dvec.clear();
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

		MenuClose->Visible = true;
		MenuEdit->Visible = true;
		EditEnabled(false);
		ButtonAccept->Visible = false;
		ButtonAdd->Visible = true;
		MenuCreate->Visible = false;
		ButtonDelete->Visible = true;
		ButtonNext->Visible = vMax>1;
		ButtonBack->Visible = vMax>1;
		MenuSearch->Visible = vMax>1;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuSaveClick(TObject *Sender)
{
	if (SaveDialog1->Execute()){
		FILE *f = fopen(AnsiString(SaveDialog1->FileName).c_str(), "wb");
		fwrite(&dvec[0],sizeof(dishes),vMax,f);
		fclose(f);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuCreateClick(TObject *Sender)
{
	ButtonAccept->Visible = true;
	EditEnabled(true);
	MenuCreate->Visible = false;
	vMax = 1;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::MenuEditClick(TObject *Sender)
{
	EditEnabled(true);
	ButtonAccept->Visible = true;
	ButtonNext->Visible = false;
	ButtonBack->Visible = false;
	ButtonAdd->Visible = false;
	ButtonDelete->Visible = false;
	MenuSearch->Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::MenuCloseClick(TObject *Sender)
{
	dvec.clear();
	vMax = 0;
	vPres = 0;
	LablePage->Caption = 0;
	LableMax->Caption = 0;
	EditName->Text = "";
	EditKitchen->Text = "";
	EditTime->Text = "";
	EditPrice->Text = "";
	MenuCreate->Visible = true;
	ButtonDelete->Visible = false;
	ButtonHave->Checked = false;
	ButtonNext->Visible = false;
	ButtonBack->Visible = false;
	ButtonAdd->Visible = false;
	MenuEdit->Visible = false;
	MenuSearch->Visible = false;
	MenuClose->Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ButtonDeleteClick(TObject *Sender)
{
	if(vMax>1){
		dvec.erase(dvec.begin()+vPres);
		vMax--;
		if(vPres != 0){
			vPres--;
		}
		LablePage->Caption = vPres + 1;
		LableMax->Caption = vMax;
		ShowPresTxt();
		MenuSave->Visible = true;
	}else if (vMax == 1) {
		EditName->Text = "";
		EditKitchen->Text = "";
		EditTime->Text = "";
		EditPrice->Text = "";
		vMax=0;
		vPres = 0;
		LablePage->Caption = 0;
		LableMax->Caption = 0;
		dvec.clear();

		MenuSave->Visible = false;
		ButtonDelete->Visible = false;
		MenuSearch->Visible = false;
		MenuEdit->Visible = false;
		MenuCreate->Visible = true;
		ButtonAdd->Visible = false;
		MenuClose->Visible = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MenuSearchClick(TObject *Sender)
{
	Form2->Visible = true;
}
//---------------------------------------------------------------------------

