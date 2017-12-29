//---------------------------------------------------------------------------

#ifndef ConnectionH
#define ConnectionH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
        TEdit *IP;
        TEdit *Port;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TButton *Button1;
        TEdit *Status;
        TLabel *Label6;
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *Back1;
        TMenuItem *ExitBattleShips1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Back1Click(TObject *Sender);
        void __fastcall ExitBattleShips1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
