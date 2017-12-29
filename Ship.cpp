//---------------------------------------------------------------------------
#pragma hdrstop
#include "Board.h"
#include "Ship.h"
#include "Player.h"
#include <algorithm>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)

Ship::Ship()
{

}

Ship::Ship(int len)
{
 length = len;
 timesHit = 0;
}

Ship::~Ship()
{

}

AnsiString Ship::checkShip(int column, int row)
{
 for(int x = 0; x < length; x++)
  if(columns[x] == column && rows[x] == row)
  {
    timesHit++;
    return "hit";
  }

 return "miss";
}

int Ship::getLength()
{
 return length;
}

int Ship::getCurrentLength()
{
 return columns.size();
}

int Ship::getColumn(int index)
{
 return columns[index];
}

int Ship::getRow(int index)
{
 return rows[index];
}

void Ship::sortPositions()
{
 if(columns.size() > 1)
 {
   sort(rows.begin(), rows.end());
   sort(columns.begin(), columns.end());
 }
}

void Ship::addPosition(int column, int row)
{
 columns.push_back(column);
 rows.push_back(row);
}

void Ship::clearPositions()
{
 columns.clear();
 rows.clear();
 timesHit = 0;
}

int Ship::getTimesHit()
{
 return timesHit;
}


