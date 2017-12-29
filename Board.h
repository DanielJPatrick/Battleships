//---------------------------------------------------------------------------

#ifndef BoardH
#define BoardH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <DBCtrls.hpp>
#include <Graphics.hpp>
#include <ScktComp.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TDrawGrid *DrawGrid1;
        TDrawGrid *DrawGrid2;
        TMemo *Chat;
        TEdit *Status;
        TClientSocket *ClientSocket1;
        TServerSocket *ServerSocket1;
        TEdit *Message;
        TButton *Send;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TButton *Button5;
        TLabel *Label4;
        TEdit *Score2;
        TEdit *Score1;
        TShape *Shape1;
        TLabel *Label5;
        TLabel *Label6;
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *ExitCurrentGame1;
        TMenuItem *ExitBattleShips1;
        void __fastcall DrawGrid1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall DrawGrid1DrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
        void __fastcall DrawGrid2DrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
        void __fastcall DrawGrid2MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall ServerSocket1ClientConnect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall ServerSocket1Listen(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall ServerSocket1GetSocket(TObject *Sender, int Socket,
          TServerClientWinSocket *&ClientSocket);
        void __fastcall ClientSocket1Connecting(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall ClientSocket1Connect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall ClientSocket1Error(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
        void __fastcall ServerSocket1ClientRead(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall SendClick(TObject *Sender);
        void __fastcall MessageKeyPress(TObject *Sender, char &Key);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Score1Change(TObject *Sender);
        void __fastcall Score2Change(TObject *Sender);
        void __fastcall ExitBattleShips1Click(TObject *Sender);
        void __fastcall ExitCurrentGame1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
