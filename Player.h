//---------------------------------------------------------------------------
#ifndef PlayerH
#define PlayerH
#include <vcl>
#include "Ship.h"
#include "Bomb.h"
#include <vector>
using namespace std;
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
class Player
{
 public:
   Player();
   ~Player();
   Ship* getShip(int);
   Bomb* getBomb(int);
   void addBomb(Bomb*);
   int getNumberOfShips();
   int getNumberOfBombs();
   int getSunkShips();
   void placeShips();
   bool checkBomb(TRect);
   void dropBomb();
   bool setPosition(int,int);
   bool checkPosition(int,int);
   void ClearShips(int);
   void ClearBombs();

 private:
   vector <Ship*> MyShips;
   vector <Bomb*> MyBombs;
};
