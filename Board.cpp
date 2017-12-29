//---------------------------------------------------------------------------
#include <vector>
#include <vcl.h>
#include <stdio.h>
#pragma hdrstop
#include "Board.h"
#include "Ship.h"
#include "Connection.h"
#include "Player.h"
#include "Mainform.h"
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

int Column1;
int Row1;
int Column2;
int Row2;
bool opponentReady;

int currentShip;
Player Player1, Player2;
extern String WhatAmI;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{

 Column1 = -1;
 Row1 = -1;
 Column2 = -1;
 Row2 = -1;
 opponentReady = false;

 currentShip = 0;
}
//---------------------------------------------------------------------------



void __fastcall TForm2::DrawGrid1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  if(currentShip < Player1.getNumberOfShips())
  {
    DrawGrid1->MouseToCell(X, Y, Column1, Row1);
    Player1.setPosition(Column1,Row1);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::DrawGrid1DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)

{
 for(int x = 0; x < Player1.getNumberOfShips(); x++)
   for(int y = 0; y < Player1.getShip(x)->getCurrentLength(); y++)
   {
     if(ARow == Player1.getShip(x)->getRow(y) && ACol == Player1.getShip(x)->getColumn(y))
     {
       switch(Player1.getShip(x)->getLength())
       {
         case(2):
           DrawGrid1->Canvas->Brush->Color = clGray;
           break;

         case(3):
           DrawGrid1->Canvas->Brush->Color = clGreen;
           break;

         case(4):
           DrawGrid1->Canvas->Brush->Color = clYellow;
           break;
       }
       DrawGrid1->Canvas->FillRect(Rect);
       DrawGrid1->Canvas->TextOut(Rect.Left, Rect.Top, IntToStr(ACol) + "," + IntToStr(ARow));
     }
   }

 if(WhatAmI == "")
   for(int x = 0; x < Player2.getNumberOfBombs(); x++)
   {
     if(Player2.getBomb(x)->getPosition() == Rect)
       if(Player2.getBomb(x)->getHit())
       {
         DrawGrid1->Canvas->Brush->Color = clRed;
         DrawGrid1->Canvas->FillRect(Rect);
         DrawGrid1->Canvas->TextOut(Rect.Left, Rect.Top, IntToStr(ACol) + "," + IntToStr(ARow));
       }
   }


 if(WhatAmI == "Host")
   ServerSocket1->Socket->Connections[0]->SendText("opponent bombs/");


 if(WhatAmI == "Client")
   ClientSocket1->Socket->SendText("opponent bombs/");

 Application->ProcessMessages();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::DrawGrid2DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{

 for(int x = 0; x < Player1.getNumberOfBombs(); x++)
 {
   DrawGrid2->MouseToCell(Player1.getBomb(x)->getPosition().Left, Player1.getBomb(x)->getPosition().Top, Column2, Row2);
   if(ARow == Row2 && ACol == Column2)
   {
     if(Player1.getBomb(x)->getHit())
       DrawGrid2->Canvas->Brush->Color = clRed;
     else
       DrawGrid2->Canvas->Brush->Color = clWhite;

     DrawGrid2->Canvas->FillRect(Rect);
     DrawGrid2->Canvas->TextOut(Rect.Left, Rect.Top, IntToStr(ACol) + "," + IntToStr(ARow));
   }
 }

}
//---------------------------------------------------------------------------

void __fastcall TForm2::DrawGrid2MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 DrawGrid2->MouseToCell(X, Y, Column2, Row2);

 Form2->Cursor = crHourGlass;

 if(Player1.checkBomb(DrawGrid2->CellRect(Column2, Row2)))
 {
   DrawGrid2->Enabled = false;
   Player1.addBomb(new Bomb(DrawGrid2->CellRect(Column2, Row2)));

   if(WhatAmI == "")
   {
     for(int x = 0; x < Player2.getNumberOfShips(); x++)
     {
       Player1.getBomb((Player1.getNumberOfBombs()-1))->setHit(Player2.getShip(x)->checkShip(Column2, Row2));
       if(Player1.getBomb((Player1.getNumberOfBombs()-1))->getHit())
         break;
     }
     Player2.dropBomb();
     Score1->Text = IntToStr(Player2.getSunkShips());
     Score2->Text = IntToStr(Player1.getSunkShips());
     DrawGrid2->Refresh();
     DrawGrid1->Refresh();
     DrawGrid2->Enabled = true;
   }

   if(WhatAmI == "Host")
   {
     DrawGrid2->Enabled = false;
     ServerSocket1->Socket->Connections[0]->SendText("check bomb*" + IntToStr(Column2) + "," + IntToStr(Row2) + "/");
     ServerSocket1->Socket->Connections[0]->SendText("turn done/");
     Application->ProcessMessages();
     Status->Text = AnsiString("Opponents Turn");
   }

   if(WhatAmI == "Client")
   {
     DrawGrid2->Enabled = false;
     ClientSocket1->Socket->SendText("check bomb*" + IntToStr(Column2) + "," + IntToStr(Row2) + "/");
     ClientSocket1->Socket->SendText("turn done/");
     Application->ProcessMessages();
     Status->Text = AnsiString("Opponents Turn");
   }
 }
 Form2->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
 if((currentShip + 1) < Player1.getNumberOfShips())
   if(Player1.getShip(currentShip)->getCurrentLength() == Player1.getShip(currentShip)->getLength())
     currentShip++;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ServerSocket1ClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
 Form2->Show();
 Form3->Hide();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::ServerSocket1Listen(TObject *Sender,
      TCustomWinSocket *Socket)
{
 Form3->Status->Text = "Waiting for opponent to join... ";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ServerSocket1GetSocket(TObject *Sender, int Socket,
      TServerClientWinSocket *&ClientSocket)
{
 Form3->Status->Text = "Connecting opponent... ";
}
//---------------------------------------------------------------------------


void __fastcall TForm2::ClientSocket1Connecting(TObject *Sender,
      TCustomWinSocket *Socket)
{
 Form3->Status->Text = "Connection to host... ";
}
//---------------------------------------------------------------------------


void __fastcall TForm2::ClientSocket1Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
 Form3->Status->Text = "Successfully connected to host... ";
 Form2->Show();
 Form3->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ClientSocket1Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
 Form3->Status->Text = "Failed to connect to host... ";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ServerSocket1ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
 AnsiString Msg;
 Msg = Socket->ReceiveText();
 bool sentCheckBombResult = false;
 int column;
 int row;
 int start = 1;

 for(int z = 1; z < (Msg.Length() + 1); z++)
   if(Msg[z] == '/')
   {
     for(int x = start; x < z; x++)
       if(Msg[x] == '*')
       {
         if(Msg.SubString(start, (x-start)) == AnsiString("check bomb"))
         {
           for(int y = (x+1); y < z; y++)
             if(Msg[y] == ',')
               {
                 column = StrToInt(Msg.SubString((x+1), ((y-1)-x)));
                 row = StrToInt(Msg.SubString((y+1), ((z-1)-y)));
                 start = z+1;
                 break;
               }

            for(int y = 0; y < Player1.getNumberOfShips(); y++)
              if(Player1.getShip(y)->checkShip(column, row) == AnsiString("hit"))
              {
                Socket->SendText("check bomb result*hit/");
                Application->ProcessMessages();
                sentCheckBombResult = true;
                Score2->Text = IntToStr(Player1.getSunkShips());
                DrawGrid1->Refresh();
                break;
              }

           if(sentCheckBombResult == false)
           {
             Socket->SendText("check bomb result*miss/");
             Application->ProcessMessages();
           }
         }

         if(Msg.SubString(start, (x-start)) == AnsiString("check bomb result"))
         {
           if(Msg.SubString((x+1),((z-1)-x)) == AnsiString("hit"))
           {
             Socket->SendText("my score/");
             Player1.getBomb((Player1.getNumberOfBombs()-1))->setHit(AnsiString("hit"));
             Application->ProcessMessages();
           }
           else
             Player1.getBomb((Player1.getNumberOfBombs()-1))->setHit(AnsiString("miss"));

           start = z+1;
           DrawGrid2->Refresh();
         }

         if(Msg.SubString(start, (x-start)) == AnsiString("my score result"))
         {
           Score1->Text = Msg.SubString((x+1), ((z-1)-x));
           start = z+1;
         }

         if(Msg.SubString(start, (x-start)) == AnsiString("chat"))
         {
           if(WhatAmI == "Host")
             Chat->Lines->Add(Socket->RemoteAddress + "(Client) sends:");

           if(WhatAmI == "Client")
             Chat->Lines->Add(Socket->RemoteAddress + "(Host) sends:");

           Chat->Lines->Add(Msg.SubString((x+1), (z-1)-x));
           Chat->Lines->Add("");
           start = z+1;
         }

         if(Msg.SubString(start, (x-start)) == AnsiString("opponent bombs result"))
         {
           for(int y = (x+1); y < (z-1); y++)
             if(Msg[y] == ',')
             {
               column = StrToInt(Msg.SubString((x+1), ((y-1)-x)));
               row = StrToInt(Msg.SubString((y+1), ((z-1)-y)));
               start = z+1;
               break;
             }

             DrawGrid1->Canvas->Brush->Color = clRed;
             DrawGrid1->Canvas->FillRect(DrawGrid1->CellRect(column, row));
             DrawGrid1->Canvas->TextOut(DrawGrid1->CellRect(column, row).Left, DrawGrid1->CellRect(column, row).Top, IntToStr(column) + "," + IntToStr(row));
        }
      }

       if(Msg.SubString(start, (z-start)) == AnsiString("my score"))
       {
         Socket->SendText("my score result*" + IntToStr(Player1.getSunkShips()) + "/");
         Application->ProcessMessages();
         start = z+1;
       }

     if(Msg.SubString(start, (z-start)) == AnsiString("opponent bombs"))
     {
       for(int y = 0; y < Player1.getNumberOfBombs(); y++)
         if(Player1.getBomb(y)->getHit())
         {
          DrawGrid1->MouseToCell(Player1.getBomb(y)->getPosition().Left, Player1.getBomb(y)->getPosition().Top, column, row);
          Socket->SendText("opponent bombs result*" + IntToStr(column) + "," + IntToStr(row) + "/");
          Application->ProcessMessages();
         }
       start = z+1;
      }

      if(Msg.SubString(start, (z-start)) == AnsiString("turn done"))
      {
        DrawGrid2->Enabled = true;
        Status->Text = AnsiString("Your Turn");
        start = z+1;
      }
      
      if(WhatAmI == "Host")
        if(Msg.SubString(start, (z-start)) == AnsiString("ready"))
          opponentReady = true;

      if(Msg.SubString(start, (z-start)) == AnsiString("disconnect"))
      {
       Application->MessageBoxA("The opponent has left the game. The game will now close", "Connection Error");
       Player1.ClearShips(-1);  // Clears all ships
       Player2.ClearShips(-1);  // Clears all ships
       Player1.ClearBombs();
       Player2.ClearBombs();
       currentShip = 0;
       Score1->Text = 0;
       Score2->Text = 0;
       opponentReady == false;
       Form1->Show();
       Form2->Hide();
       Chat->Clear();
       Form3->Status->Text = "";
       ServerSocket1->Active = false;
       ClientSocket1->Active = false;
      }
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm2::SendClick(TObject *Sender)
{
 if(WhatAmI == "Host")
 {
  Chat->Lines->Add(Form2->ServerSocket1->Socket->Connections[0]->LocalAddress + "(Host) sends:");
  Chat->Lines->Add(Message->Text);
  Chat->Lines->Add("");
  ServerSocket1->Socket->Connections[0]->SendText("chat*" + Message->Text + "/");
 }

 if(WhatAmI == "Client")
 {
  Chat->Lines->Add(ClientSocket1->Socket->LocalAddress + "(Client) sends:");
  Chat->Lines->Add(Message->Text);
  Chat->Lines->Add("");
  ClientSocket1->Socket->SendText("chat*" + Message->Text + "/");
 }

 Application->ProcessMessages();
 Message->Text = "";
}
//---------------------------------------------------------------------------






void __fastcall TForm2::MessageKeyPress(TObject *Sender, char &Key)
{
 if(int(Key) == 13)
   Send->Click();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button4Click(TObject *Sender)
{
 if(WhatAmI == "" || WhatAmI == "Client" || (WhatAmI == "Host" & opponentReady == true))
   if((currentShip + 1) >= Player1.getNumberOfShips())
   {
     Button4->Cursor = crHourGlass;
     Button1->Visible = false;
     Button2->Visible = false;
     Button3->Visible = false;
     Button4->Visible = false;
     Button5->Visible = false;
     Score1->Visible = true;
     Score2->Visible = true;
     Label4->Visible = true;
     Label5->Visible = true;
     Label6->Visible = true;
     Shape1->Visible = true;
     Player2.ClearShips(-1);  // clears all ships
     Player2.placeShips();
     DrawGrid1->Enabled = false;
     DrawGrid2->Enabled = true;
     Button4->Cursor = crDefault;

     if(WhatAmI == "Host")
     {
       Status->Text = AnsiString("Your Turn");
       DrawGrid2->Enabled = true;
     }

     if(WhatAmI == "Client")
     {
       DrawGrid2->Enabled = false;
       Status->Text = AnsiString("Opponents Turn");
       ClientSocket1->Socket->SendText("ready/");
       Application->ProcessMessages();
     }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{
 Player1.ClearShips(currentShip);
 DrawGrid1->Visible = false;
 DrawGrid1->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button5Click(TObject *Sender)
{
 Button5->Cursor = crHourGlass;
 Button1->Enabled = false;
 Button2->Enabled = false;
 Button3->Enabled = false;
 Button4->Enabled = false;
 Button5->Enabled = false;
 Player1.ClearShips(-1);  // clears all ships
 Player1.placeShips();
 DrawGrid1->Visible = false;
 DrawGrid1->Visible = true;
 Button1->Enabled = true;
 Button2->Enabled = true;
 Button3->Enabled = true;
 Button4->Enabled = true;
 Button5->Enabled = true;
 Button5->Cursor = crDefault;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button2Click(TObject *Sender)
{
 Player1.ClearShips(-1);  // clears all ships
 currentShip = 0;
 DrawGrid1->Visible = false;
 DrawGrid1->Visible = true;
}
//---------------------------------------------------------------------------



void __fastcall TForm2::Score1Change(TObject *Sender)
{
 if(Score1->Text == AnsiString("8"))
 {
   Application->MessageBoxA("You Win!", "Game Result");
   Player1.ClearShips(-1); // Clears all ships
   Player2.ClearShips(-1); // Clears all ships
   Player1.ClearBombs();
   Player2.ClearBombs();
   currentShip = 0;
   Score1->Text = 0;
   Score2->Text = 0;
   opponentReady == false;
   Chat->Clear();
   Form1->Show();
   Form2->Hide();
   Form3->Status->Text = "";
   Status->Text = "";
   ServerSocket1->Active = false;
   ClientSocket1->Active = false;
 }

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Score2Change(TObject *Sender)
{
 if(Score2->Text == AnsiString("8"))
 {
   Application->MessageBoxA("You Lose!", "Game Result");
   Player1.ClearShips(-1);  // Clears all ships
   Player2.ClearShips(-1);  // Clears all ships
   Player1.ClearBombs();
   Player2.ClearBombs();
   currentShip = 0;
   Score1->Text = 0;
   Score2->Text = 0;
   opponentReady == false;
   Chat->Clear();
   Form1->Show();
   Form2->Hide();
   Form3->Status->Text = "";
   Status->Text = "";
   ServerSocket1->Active = false;
   ClientSocket1->Active = false;
 }
}
//---------------------------------------------------------------------------


void __fastcall TForm2::ExitBattleShips1Click(TObject *Sender)
{
 if(WhatAmI == "Host")
   ServerSocket1->Socket->Connections[0]->SendText("disconnect/");

 if(WhatAmI == "Client")
   ClientSocket1->Socket->SendText("disconnect/");

 Application->ProcessMessages();
 ServerSocket1->Active = false;
 ClientSocket1->Active = false;
 Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ExitCurrentGame1Click(TObject *Sender)
{
 if(WhatAmI == "Host")
   ServerSocket1->Socket->Connections[0]->SendText("disconnect/");

 if(WhatAmI == "Client")
   ClientSocket1->Socket->SendText("disconnect/");

 Application->ProcessMessages();
 Player1.ClearShips(-1);  // Clears all ships
 Player2.ClearShips(-1);  // Clears all ships
 Player1.ClearBombs();
 Player2.ClearBombs();
 currentShip = 0;
 Score1->Text = 0;
 Score2->Text = 0;
 opponentReady == false;
 Form1->Show();
 Form2->Hide();
 Chat->Clear();
 Form3->Status->Text = "";
 Status->Text = "";
 ServerSocket1->Active = false;
 ClientSocket1->Active = false;
}
//---------------------------------------------------------------------------



