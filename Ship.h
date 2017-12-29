//---------------------------------------------------------------------------
#ifndef ShipH
#define ShipH
#include <vector>
#include <string>;
using namespace std;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
class Ship
{
 public:
   Ship(int);
   ~Ship();
   AnsiString checkShip(int,int);
   int getColumn(int);
   int getRow(int);
   int getTimesHit();
   int getLength();
   int getCurrentLength();
   void sortPositions();
   void addPosition(int, int);
   void clearPositions();

 private:
   int length;
   int timesHit;
   Ship();
   vector <int> columns;
   vector <int> rows;
};
//---------------------------------------------------------------------------
#endif
