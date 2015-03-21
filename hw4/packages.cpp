/*
 * Name: GIACONE, JORDAN
 * Class and Section: CS153, Section C
 * Date: 4-1-14
 */

#include <iostream>
#include <iomanip>
#include "TwoDPackage.h"
#include "ThreeDPackage.h"
#include "FourDPackage.h"

using namespace std;

int main()
{
    cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    cout.precision(2);

    int numLoops, packageType;
    float length, width, height, time, weight, totalProfit = 0;
    string to, from;
    cin >> numLoops;
    AbstractPackage* package[500];

    for(int i = 0; i < numLoops; i++)
    {
      cin >> packageType;
      cin >> from;
      cin >> to;
      cin >> length;
      cin >> width;

      switch(packageType)
      {
        case 2:
          package[i] = new TwoDPackage(from, to, length, width, 0);
          break;
        case 3:
          cin >> height;
          cin >> weight;
          package[i] = new ThreeDPackage(from, to, length, width, height, weight);
          break;
        case 4:
          cin >> height;
          cin >> time;
          cin >> weight;
          package[i] = new FourDPackage(from, to, length, width, height, time, weight);
          break;
        default:
          cout << "Improper Package!" << endl;
          break;
      }
    }
    for(int i = 0; i < numLoops; i++)
    {
      cout << "#" << i << ": From " << package[i]->getFrom() << " to " << package[i]->getTo() << "\n$" << (package[i]->getCharge()) << endl;
      totalProfit += package[i]->getCharge();

      delete package[i];
    }

    cout << "TOTAL PROFIT = " << totalProfit << "\nAVERAGE = " << (totalProfit / numLoops) << endl;

    return 0;
}
