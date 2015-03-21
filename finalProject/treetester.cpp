#include <iostream>
#include "MyBSTree.h"
using namespace std;


//------------------------------------------------------
void test1()
{
  MyBSTree<int> t, t1;

  cout << endl << endl << "***** " << "Test #1" << endl;

  t.print();
  cout << "Tree empty? " << boolalpha << t.isEmpty() << endl;

  cout << "--" << endl;

  t.insert(7);
  t.insert(5);
  t.insert(9);
  t.insert(4);
  t.insert(6);
  t.insert(13);
  t.insert(10);


  t.print();
  cout << "Tree empty? " << boolalpha << t.isEmpty() << endl;
  cout << "--" << endl;
  cout << "height = " << t.height() << endl;
  cout << "size = " << t.size() << endl;
  cout << "--" << endl;
  for(int i = 0; i < 10; i++)
  {
    cout << "Contains " << i + 1 << "? Found on level " << t.contains(i + 1) << endl;
  }
  cout << "Contains 100? Found on level " << t.contains(100) << endl;
  t.clear();
  cout << "Level of 8 is " << t.contains(8) << endl;
  t.insert(7);
  cout << "Level of 8 is " << t.contains(8) << endl;
  t = t1;

  cout << "Contains 100? Found on level " << t1.contains(100) << endl;

  return;
}


//------------------------------------------------------
void test2()
{
  MyBSTree<char> t;

  cout << endl << endl << "***** " << "Test #2" << endl;

  t.insert('F');
  t.insert('A');
  t.insert('C');
  t.insert('G');
  t.insert('B');
  t.insert('S');
  t.insert('K');
  t.insert('U');
  t.insert('L');
  t.insert('K');

  t.print();
  cout << "--" << endl;
  cout << "Min = " << t.findMin() << endl;
  cout << "Max = " << t.findMax() << endl;

  return;
}


//------------------------------------------------------
void test3()
{
  MyBSTree<string> t;
  MyBSTree<string> t2;

  cout << endl << endl << "***** " << "Test #3" << endl;

  t.insert(string("Paul"));
  t.insert(string("John"));
  t.insert(string("George"));
  t.insert(string("Ringo"));
  t.insert(string("Fry"));
  t.insert(string("Leela"));
  t.insert(string("Zoidberg"));


  t.print();
  cout << "--" << endl;
  cout << "Testing Operator = " << endl;
  t2 = t;
  t2.print();

  cout << "--" << endl;
  cout << "Is it a deep copy? " << endl;
  t2.remove(string("George"));
  t2.remove(string("John"));
  t2.remove(string("Ringo"));
  cout << "-- copy:" << endl;
  t2.print();
  cout << "-- original:" << endl;
  t.print();

  return;
}


//------------------------------------------------------
void test4()
{
  MyBSTree<string> t;

  cout << endl << endl << "***** " << "Test #4" << endl;

  t.insert(string("Pizza"));
  t.insert(string("Burger"));
  t.insert(string("HotDog"));
  t.insert(string("Shake"));
  t.insert(string("Fry"));
  t.insert(string("Salad"));
  t.insert(string("Soda"));


  t.print();
  cout << "--" << endl;
  cout << "Testing Copy COnstructor " << endl;
  MyBSTree<string> t2(t);
  t2.print();

  cout << "--" << endl;
  cout << "Is it a deep copy? " << endl;
  t2.remove(string("Pizza"));
  t2.remove(string("Salad"));
  t2.remove(string("Fry"));
  cout << "-- copy:" << endl;
  t2.print();
  cout << "-- original:" << endl;
  t.print();

  return;
}

void test5()
{
  MyBSTree<int> t;

  cout << endl << endl << "***** " << "Test #5" << endl;
  cout << "Tree empty? " << boolalpha << t.isEmpty() << endl;
  cout << "--" << endl;

  try {
    t.findMin();
  }
  catch (string errmsg)
  {
    cout << errmsg << endl;
  }

  try {
    t.findMax();
  }
  catch (string errmsg)
  {
    cout << errmsg << endl;
  }

  return;
}


//------------------------------------------------------
void test6()
{
  MyBSTree<int> t;

  cout << endl << endl << "***** " << "Test #6" << endl;

  cout << "--" << endl;

  t.insert(7);
  t.insert(5);
  t.insert(9);
  t.insert(4);
  t.insert(6);
  t.insert(13);
  t.insert(10);


  t.print();

  cout << "--" << endl;
  cout << "Pre Order:" << endl;
  t.printPreOrder();

  cout << "--" << endl;
  cout << "Post Order" << endl;
  t.printPostOrder();

  return;
}

//------------------------------------------------------
//------------------------------------------------------
//------------------------------------------------------
//------------------------------------------------------
int main ()
{
  cout << "Hello Tree Tester!! " << endl;

  test1();
  test2();
  test3();
  test4();
  test5();
  test6();

  return 0;
}


