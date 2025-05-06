#include <iostream>

using namespace std;
string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
string names[3];
int main()
{

    for (int i = 0; i < 4; i++)
    {
        cout << i << cars[i] << endl;
    }

    // foreach loop

    for (string i : cars)
    {
        cout << i;
    }

    names[0] = "ming";
    names[1] = "zing";
    names[2] = "tenz";

    cout << names;

    int num = 10;
    int *pointer = $num;
    cout << pointer;
    return 0;
}