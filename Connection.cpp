//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <string>
#include "Connection.h"
#include "Mainform.h"
#include "Board.h"
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
extern String WhatAmI;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
 if(WhatAmI == "Host")
 {
   if(Port->Text != "")
     Form2->ServerSocket1->Port = StrToInt(Port->Text);
   else
     Form2->ServerSocket1->Port = 7676;

   Form2->ServerSocket1->Active = true;
 }

 if(WhatAmI == "Client")
 {
  if(Port->Text != "")
    Form2->ClientSocket1->Port = StrToInt(Port->Text);
  else
    Form2->ClientSocket1->Port = 7676;

    Form2->ClientSocket1->Host = Form3->IP->Text;
    Form2->ClientSocket1->Active = true;
 }
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Back1Click(TObject *Sender)
{
 Form2->ServerSocket1->Active = false;
 Form2->ClientSocket1->Active = false;
 Form1->Show();
 Form3->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::ExitBattleShips1Click(TObject *Sender)
{
 Form2->ServerSocket1->Active = false;
 Form2->ClientSocket1->Active = false;
 Application->Terminate();
}
//---------------------------------------------------------------------------

