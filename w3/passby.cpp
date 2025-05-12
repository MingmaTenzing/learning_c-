#include <iostream>

using namespace std;

void sum_by_value(int num1, int num2);

void sum_by_pointer(int *num1, int *num2);
int main()
{

    int firstNum = 10;
    int secondNum = 3;

    cout << "this is address" << &firstNum << " and " << &secondNum << endl;
    sum_by_value(firstNum, secondNum);
    sum_by_pointer(&firstNum, &secondNum);

    return 0;
}

void sum_by_value(int num1, int num2)
{

    cout << num1 + num2 << endl;
}
void sum_by_pointer(int *num1, int *num2)
{

    cout << "this sum is by using pointers";

    cout << *num1 + *num2 << endl;
}