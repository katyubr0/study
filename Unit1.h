//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
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
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonBackClick(TObject *Sender);
	void __fastcall ButtonNextClick(TObject *Sender);
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
