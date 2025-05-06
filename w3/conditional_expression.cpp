#include <iostream>

using namespace std;

int num1, num2, larger;
int main()
{
    cout << "enter a number" << endl;
    cin >> num1;
    cout << "enter second number" << endl;
    cin >> num2;
    larger = num1 > num2 ? num1 : num2;
    cout << "the larger number between" << num1 << "and" << num2 << "is : " << larger << endl;

    return 0;
}
