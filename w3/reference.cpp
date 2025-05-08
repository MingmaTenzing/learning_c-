#include <iostream>
using namespace std;

int main()
{

    string food = "Pizza";
    string &meal = food;

    cout << "this is food : " << food << endl;
    cout << " this is meal : " << meal << endl;

    meal = "rice";
    cout << "after changing value of meal the value of food is : " << food << endl;

    food = "dall";
    cout << meal;

    cout << food;

    cout << &meal << endl;
    cout << &food << endl;

    return 0;
}