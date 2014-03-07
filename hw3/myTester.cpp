#include "linkedlist.h"
#include <iostream>

using namespace std;
int main()
{
  LinkedList<int> l;

  cout << l.size() << endl;
  l.clear();
  return 0;
}
