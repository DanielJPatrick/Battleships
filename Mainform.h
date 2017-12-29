//---------------------------------------------------------------------------

#ifndef MainformH
#define MainformH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Menus.hpp>
#include <ScktComp.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *NewGame1;
        TMenuItem *Exit1;
        TMenuItem *PlayComputer1;
        TMenuItem *HostGame2;
        TMenuItem *JoinGame2;
        TMenuItem *About1;
        TLabel *Label1;
        void __fastcall PlayComputer1Click(TObject *Sender);
        void __fastcall HostGame2Click(TObject *Sender);
        void __fastcall JoinGame2Click(TObject *Sender);
        void __fastcall About1Click(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
