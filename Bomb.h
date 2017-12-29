//---------------------------------------------------------------------------
#include <vcl>
#ifndef BombH
#define BombH
//---------------------------------------------------------------------------
class Bomb
{
 public:
   Bomb(TRect);
   void setPosition(TRect);
   void setHit(AnsiString);
   TRect getPosition();
   bool getHit();

 private:
   Bomb();
   bool Hit;
   TRect Position;
};

#endif
