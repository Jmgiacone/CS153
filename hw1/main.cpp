#include <iostream>
#include "gmatrix.h"

using namespace std;

int main()
{
    int seed = 10, d = 5;
    GMatrix* matrix;
    for(int i = 1; i < 15000; i++)
    {
        matrix = new GMatrix(i, i, seed, d);
        cout << (*matrix) << endl;
        delete matrix;
        matrix = NULL;
    }
    return 0;
}