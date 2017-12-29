//---------------------------------------------------------------------------
#pragma hdrstop
#include "Player.h"
#include "Board.h"
#include <stdlib.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
extern int currentShip;
int currentTarget = -1;
int hitColumn = -1;
int hitRow = -1;
int firstHitColumn = -1;
int firstHitRow = -1;
bool rowUp;
bool rowDown;
bool columnUp;
bool columnDown;
extern Player Player1;
//---------------------------------------------------------------------------
Player::Player()
{
 for(int x = 0; x < 3; x++)
   MyShips.push_back(new Ship(2));

 for(int x = 0; x < 3; x++)
   MyShips.push_back(new Ship(3));

 for(int x = 0; x < 2; x++)
   MyShips.push_back(new Ship(4));
}

Player::~Player()
{
 for(int x = 0; x < getNumberOfShips(); x++)
   delete MyShips[x];

 for(int x = 0; x < getNumberOfBombs(); x++)
   delete MyBombs[x];
}

void Player::placeShips()
{
 int column;
 int row;
 int decider;
 int direction;
 int countAvailableSpace;
 currentShip = 0;

 for(int x = 0; x < getNumberOfShips(); x++)
 {
   do{
     randomize();

     decider = random(2);

     if(decider == 0)
       direction = 1;
     else
       direction = -1;

     randomize();

     decider = random(2);

     column = random(20);
     row = random(10);

     countAvailableSpace = 0;

     while(setPosition(column, row) == false)
     {
       MyShips[x]->clearPositions();
       column = random(20);
       row = random(10);
     }

     countAvailableSpace++;

     if(decider == 0)
     {
       for(int y = 1; y < MyShips[x]->getLength(); y++)
         if((column + (direction * y)) > -1 && (column + (direction * y)) < 20)
           if(setPosition((column + (direction * y)), row))
             countAvailableSpace++;
           else
           {
             MyShips[x]->clearPositions();
             break;
           }
         else
         {
           MyShips[x]->clearPositions();
           break;
         }
     }

     if(decider == 1)
     {
       for(int y = 1; y < MyShips[x]->getLength(); y++)
         if((row + (direction * y)) > -1 && (row + (direction * y)) < 10)
           if(setPosition(column, (row + (direction * y))))
             countAvailableSpace++;
           else
           {
             MyShips[x]->clearPositions();
             break;
           }
         else
         {
           MyShips[x]->clearPositions();
           break;
         }
     }
   }while(countAvailableSpace != MyShips[x]->getLength());
   currentShip++;
 }
}

Bomb* Player::getBomb(int index)
{
 if(index > -1 && index < MyBombs.size())
   return MyBombs[index];
}

void Player::addBomb(Bomb* bomb)
{
 MyBombs.push_back(bomb);
}

int Player::getNumberOfBombs()
{
 return MyBombs.size();
}

int Player::getNumberOfShips()
{
 return MyShips.size();
}

Ship* Player::getShip(int index)
{
 if(index > -1 && index < MyShips.size())
   return MyShips[index];
}

bool Player::setPosition(int column,int row)
{
 if(MyShips.size() == 0)
   return false;

 MyShips[currentShip]->sortPositions();

 if(checkPosition(column,row))
 {
   MyShips[currentShip]->addPosition(column,row);
   return true;
 }
 return false;
}

bool Player::checkPosition(int column,int row)
{
 bool nextDoor1 = true;
 bool nextDoor2 = true;

 if(MyShips[currentShip]->getCurrentLength() == MyShips[currentShip]->getLength())
    return false;

 for(int x = 0; x < MyShips.size(); x++)
   for(int y = 0; y < MyShips[x]->getCurrentLength(); y++)
   {
     if(MyShips[x]->getColumn(y) == column && MyShips[x]->getRow(y) == row)
       return false;
     if(x == currentShip && MyShips[x]->getColumn(y) != column && MyShips[x]->getRow(y) != row)
       return false;
   }

 if(MyShips[currentShip]->getCurrentLength() > 0)
 {
   if(MyShips[currentShip]->getColumn(MyShips[currentShip]->getCurrentLength() -1) -1 != column && MyShips[currentShip]->getColumn(MyShips[currentShip]->getCurrentLength() -1) +1 != column && MyShips[currentShip]->getRow(MyShips[currentShip]->getCurrentLength() -1) == row)
     nextDoor2 = false;

   if(MyShips[currentShip]->getRow(MyShips[currentShip]->getCurrentLength() -1) -1 != row && MyShips[currentShip]->getRow(MyShips[currentShip]->getCurrentLength() -1) +1 != row && MyShips[currentShip]->getColumn(MyShips[currentShip]->getCurrentLength() -1) == column)
     nextDoor2 = false;

   if(MyShips[currentShip]->getColumn(0) -1 != column && MyShips[currentShip]->getColumn(0) +1 != column && MyShips[currentShip]->getRow(0) == row)
     nextDoor1 = false;

   if(MyShips[currentShip]->getRow(0) -1 != row && MyShips[currentShip]->getRow(0) +1 != row && MyShips[currentShip]->getColumn(0) == column)
     nextDoor1 = false;

   if(nextDoor1 == false && nextDoor2 == false)
     return false;

 }
 return true;
}

void Player::ClearShips(int index)
{
 if(index == -1)
   for(int x = 0; x < getNumberOfShips(); x++)
     MyShips[x]->clearPositions();

 else
   MyShips[index]->clearPositions();
}

void Player::ClearBombs()
{
 for(int x = 0; x < getNumberOfBombs(); x++)
   delete MyBombs[x];

   MyBombs.clear();
}

void Player::dropBomb()
{
 bool goodPosition = false;
 int column;
 int row;
 int decider;
 int direction;
 randomize();
 columnDown = false;
 columnUp = false;
 rowUp = false;
 rowDown = false;

 do{

   if(currentTarget == -1)
   {
     column = random(20);
     row = random(10);
   }

   else
   {
       decider = random(2);

       if(decider == 0)
         direction = 1;
       else
         direction = -1;

     randomize();

     decider = random(2);

     if(hitColumn != -1)
     {
       column = hitColumn;
       row = hitRow;
     }

     if(rowUp == true && rowDown == true && columnUp == true && columnDown == true)
       if(firstHitColumn != -1)
       {
         column = firstHitColumn;
         row = firstHitRow;
         columnDown = false;
         columnUp = false;
         rowUp = false;
         rowDown = false;
       }

     if(direction == 1 && columnUp == true && rowUp == true)
       direction = -1;

     if(direction == -1 && columnDown == true && rowDown == true)
       direction = 1;

     if(decider == 0 && columnDown == true && columnUp == true)
       decider = 1;

     if(decider == 1 && rowDown == true && rowUp == true)
       decider = 0;

     if(decider == 0)
     {
       if((column + direction) > -1 && (column + direction) < 20)
         column = column + direction;

       if(direction == 1)
         columnUp  = true;

       if(direction == -1)
         columnDown = true;
     }

     if(decider == 1)
     {
       if((row + direction) > -1 && (row + direction) < 10)
         row = row + direction;

       if(direction == 1)
         rowUp  = true;

       if(direction == -1)
         rowDown = true;
     }

   }

   if(checkBomb(Form2->DrawGrid2->CellRect(column, row)))
   {
     MyBombs.push_back(new Bomb(Form2->DrawGrid2->CellRect(column, row)));
     goodPosition = true;
   }

 }while(goodPosition == false);

 for(int x = 0; x < Player1.getNumberOfShips(); x++)
 {
   MyBombs[(MyBombs.size()-1)]->setHit(Player1.getShip(x)->checkShip(column, row));
     if(MyBombs[(MyBombs.size()-1)]->getHit())
     {
       hitColumn = column;
       hitRow = row;

       if(Player1.getShip(x)->getLength() != Player1.getShip(x)->getTimesHit())
       {
         currentTarget = x;
         if(Player1.getShip(x)->getTimesHit() == 1)
         {
           firstHitColumn = column;
           firstHitRow = row;
         }
         break;
       }
       else
       {
         hitColumn = -1;
         hitRow = -1;
         currentTarget = -1;
         firstHitColumn = -1;
         firstHitRow = -1;
         columnDown = false;
         columnUp = false;
         rowUp = false;
         rowDown = false;
         break;
       }
     }
 }
}

bool Player::checkBomb(TRect Pos)
{
 for(int x = 0; x < getNumberOfBombs(); x++)
  if(getBomb(x)->getPosition() == Pos)
    return false;

 return true;
}

int Player::getSunkShips()
{
 int SunkShips = 0;
 for(int x = 0; x < MyShips.size(); x++)
   if(MyShips[x]->getTimesHit() == MyShips[x]->getLength())
     SunkShips++;

 return SunkShips;
}

