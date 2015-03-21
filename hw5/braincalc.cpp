#include <string>
#include <cstdlib>
#include <iostream>
#include "LinkedListStack.h"

using namespace std;
int main()
{
  LinkedListStack<int> s;

  string str = "";
  int left, right, result;

  cin >> str;

  while(str != "#")
  {
    if(str == "$")
    {
      cout << "[ ";

      while(!s.isEmpty())
      {
        if(s.size == 1)
        {
          cout << s.top() << " ";
        }
        else
        {
          cout << s.top() << ", ";
        }

        s.pop();
      }

      cout << "]" << endl;
    }
    else if(str == "+" || str == "-" || str == "*" || str == "/" || str == "%" || str == "!")
    {
       right = s.top();
       s.pop();

       if(s.size >= 1)
       {
         left = s.top();
         s.pop();
       }

       if(str == "+")
       {
         result = left + right;
       }
       else if(str == "-")
       {
           result = left - right;
       }
       else if(str == "*")
       {
           result = left * right;
       }
       else if(str == "/")
       {
           result = left / right;
       }
       else if(str == "%")
       {
           result = left % right;
       }
       else
       {
           result = -1 * right;
       }

       s.push(result);
    }
    else
    {
      result = atoi(str.c_str());
      s.push(result);
    }

    cin >> str;
  }

  return 0;
}
