//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <string>
#include "Mainform.h"
#include "Board.h"
#include "Connection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

String WhatAmI;

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PlayComputer1Click(TObject *Sender)
{
 Form2->Show();
 Form1->Hide();
 WhatAmI = "";
 Form2->Message->Enabled = false;
 Form2->Chat->Enabled = false;
 Form2->Status->Enabled = false;
 Form2->DrawGrid2->Enabled = false;
 Form2->Send->Enabled = false;
 Form2->Button1->Visible = true;
 Form2->Button2->Visible = true;
 Form2->Button3->Visible = true;
 Form2->Button4->Visible = true;
 Form2->Button5->Visible = true;
 Form2->Score1->Visible = false;
 Form2->Score2->Visible = false;
 Form2->Label4->Visible = false;
 Form2->Label5->Visible = false;
 Form2->Label6->Visible = false;
 Form2->Shape1->Visible = false;
 Form2->DrawGrid2->Enabled = false;
 Form2->DrawGrid1->Enabled = true;
 Form2->Score2->Text = 0;
 Form2->Score1->Text = 0;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::HostGame2Click(TObject *Sender)
{
 Form3->Button1->Caption = "Host Game";
 WhatAmI = "Host";
 Form3->IP->Enabled = false;
 Form3->Show();
 Form1->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::JoinGame2Click(TObject *Sender)
{
 Form3->Button1->Caption = "Join Game";
 WhatAmI = "Client";

 if(Form3->IP->Enabled == false)
   Form3->IP->Enabled == true;

 Form3->Show();
 Form1->Hide();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::About1Click(TObject *Sender)
{
 Application->MessageBoxA("Daniel's Battleship Program version 1.0 - Submitted for programming Assignment 3 at WelTec", "About");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Exit1Click(TObject *Sender)
{
 Application->Terminate();
}
//---------------------------------------------------------------------------

