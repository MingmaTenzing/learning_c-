#include <iostream>
using namespace std;

double calcEarning(int rate, double hours);

int main()
{
    int enter_rate;
    double working_hours, pay;

    cout << "enter the rate " << endl;
    cin >> enter_rate;

    cout << "enter working hours" << endl;
    cin >> working_hours;

    pay = calcEarning(enter_rate, working_hours);
    cout << "the pay for this week is : " << pay << endl;

    return 0;
}

double calcEarning(int rate, double hours)
{
    return rate * hours;
}