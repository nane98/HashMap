#include <iostream>
#include <string>
using namespace std;
#include "hashTable.h"

int main()
{
    HashMap<int, int> ob;
    ob.put(5, 4);
    ob.put(2, 3);
    ob.put(5, 1);
    ob.put(1, 4);
    ob.put(25, 2);
    ob.put(25, 2);
    ob.put(10, 4);
    cout << "sz: " << ob.size() << endl;
    ob.print();
    ob.empty();
    cout << "sz: " << ob.size() << endl;
    ob.print();
    return 0;
}
