//---------------------------------------------------------------------------
#pragma hdrstop

#include "Bomb.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

Bomb::Bomb()
{

}

Bomb::Bomb(TRect Pos)
{
 Position = Pos;
}

void Bomb::setPosition(TRect Pos)
{
 Position = Pos;
}

void Bomb::setHit(AnsiString Target)
{
 if(Target == "hit")
   Hit = true;
 else
   Hit = false;
}

TRect Bomb::getPosition()
{
 return Position;
}

bool Bomb::getHit()
{
 return Hit;
}