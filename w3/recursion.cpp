#include <iostream>

using namespace std;

int sum(int k);
int main()
{

    int result = sum(10);
    cout << result << endl;

    return 0;
}

int sum(int k)
{

    if (k > 0)
    {
        return k + sum(k - 1);
    }
    return 0;
}
