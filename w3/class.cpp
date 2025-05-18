#include <iostream>

using namespace std;

class Human
{
public:
    int age;
    string name;
    string country;

    Human(int a, string n, string c)
    {
        age = a;
        name = n;
        country = c;
    };

    void print_details()
    {
        cout << "Human name is :" << name << endl;
        cout << name << "is from " << country << endl;

        cout << name << "'s age is " << age << endl;
    }
};

int main()
{
    Human firsthuman(10, "Tenzing", "Australia");
    firsthuman.print_details();

    return 0;
}