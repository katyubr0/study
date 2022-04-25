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
#include <algorithm>

using namespace std;
//---------------------------------------------------------------------------
class dishes{
	public:
		char name[30];
		char kitchen[30];
		int time;
		int price;
		bool have;

		bool friend operator==(const dishes &a, const dishes &b){
			return(
				strcmp (a.name, b.name)==0 ||
				strcmp (a.kitchen, b.kitchen)==0 ||
				a.time == b.time ||
				a.price == b.price
				);
		}
};
//----------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *EditName;
	TEdit *EditKitchen;
	TEdit *EditTime;
	TEdit *EditPrice;
	TCheckBox *ButtonHave;

	TButton *ButtonNext;
	TButton *ButtonBack;
	TButton *ButtonAdd;
	TButton *ButtonAccept;

	TLabel *LablePage;
	TLabel *LabelName;
	TLabel *LabelKitchen;
	TLabel *LabelTime;
	TLabel *LabelPrice;
	TLabel *Label7;
	TLabel *LableMax;
	TMainMenu *MainMenu;
	TMenuItem *MenuCreate;
	TMenuItem *MenuEdit;
	TMenuItem *MenuSave;
	TMenuItem *MenuOpen;
	TMenuItem *MenuClose;

	TImageList *ImageList1;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TButton *ButtonDelete;
	TMenuItem *MenuSearch;

	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonBackClick(TObject *Sender);
	void __fastcall ButtonNextClick(TObject *Sender);
	void __fastcall ButtonAcceptClick(TObject *Sender);
	void __fastcall MenuOpenClick(TObject *Sender);
	void __fastcall MenuSaveClick(TObject *Sender);
	void __fastcall MenuCreateClick(TObject *Sender);
	void __fastcall MenuEditClick(TObject *Sender);
	void __fastcall MenuCloseClick(TObject *Sender);
	void __fastcall ButtonDeleteClick(TObject *Sender);
	void __fastcall MenuSearchClick(TObject *Sender);
private:
public:
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
extern int vMax, vPres;
extern std::vector <dishes> dvec;
extern std::vector<TButton *> buttonList;
extern std::vector <TMenuItem *> menuList;
//---------------------------------------------------------------------------
#endif
