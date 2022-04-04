//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ActnCtrls.hpp>
#include <Vcl.ActnMan.hpp>
#include <Vcl.ActnMenus.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ImgList.hpp>
#include <vector>
#include <string>
using namespace std;
//---------------------------------------------------------------------------
class dishes{
	public:
		char name[30];
		char kitchen[30];
		char time[30];
		char price[30];
		bool have;
};
//----------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *EditName;
	TEdit *EditKitchen;
	TEdit *EditTime;
	TEdit *EditPrice;
	TLabel *LablePage;
	TButton *ButtonNext;
	TButton *ButtonBack;
	TButton *ButtonAdd;
	TLabel *LabelName;
	TLabel *LabelKitchen;
	TLabel *LabelTime;
	TLabel *LabelPrice;
	TLabel *Label7;
	TLabel *LableMax;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TButton *ButtonAccept;
	TMainMenu *MainMenu1;
	TMenuItem *dfgh1;
	TMenuItem *MenuCreate;
	TMenuItem *MenuEdit;
	TMenuItem *MenuSave;
	TMenuItem *MenuOpen;
	TMenuItem *MenuClose;
	TCheckBox *ButtonHave;
	TImageList *ImageList1;
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonBackClick(TObject *Sender);
	void __fastcall ButtonNextClick(TObject *Sender);
	void __fastcall ButtonAcceptClick(TObject *Sender);
	void __fastcall MenuOpenClick(TObject *Sender);
	void __fastcall MenuSaveClick(TObject *Sender);
	void __fastcall MenuCreateClick(TObject *Sender);
	void __fastcall MenuEditClick(TObject *Sender);
	void __fastcall MenuCloseClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
extern int vMax, vPres;
extern std::vector <dishes> dvec;
//---------------------------------------------------------------------------
#endif
