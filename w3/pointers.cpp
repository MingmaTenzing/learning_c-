#include <iostream>

using namespace std;

int main()
{

    string food = "pizza";

    string &rfood = food;
    string *ptr = &food;

    cout << &rfood << endl;

    cout << *ptr << endl;

    return 0;
}