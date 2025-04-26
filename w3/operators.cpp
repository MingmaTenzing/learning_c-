#include <iostream>
using namespace std;

int main()
{
    int x = 6;
    bool result;

    if (x > 5)
    {
        cout << "x is greater than 5 current value is " << x << "\n";
    }

    result = x > 5 && x < 10;
    cout << result << "\n";

    return 0;
}