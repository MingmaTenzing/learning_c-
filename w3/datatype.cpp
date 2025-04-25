#include <iostream>
#include <string>
using namespace std;

int num = 5;
float myfloat = 4.33;
double doublenumber = 9.999;
char myLetter = 'A';
string name = "hello world";

int main()
{
    cout << name << "\n";
    cout << num << "\n";
    cout << myfloat;
    cout << doublenumber;
    cout << myLetter << "\n";

    cout << name.length();

    return 0;
}