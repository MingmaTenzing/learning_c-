#include <iostream>

using namespace std;

int main()
{

    for (int i = 0; i < 10; i++)
    {
        cout << i;

        if (i == 5)
        {
            cout << "ok this is 5" << endl;
            break;
        }
    }

    return 0;
}