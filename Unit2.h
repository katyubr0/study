//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TEdit *EditSearchName;
	TButton *ButtonSearch;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *EditSearchKitchen;
	TEdit *EditSearchTime;
	TEdit *EditSearchPrice;
	void __fastcall ButtonSearchClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
extern int i;
//---------------------------------------------------------------------------
#endif
