#include <iostream>

using namespace std;

template <typename ageT, typename strT>

class Human
{
public:
    ageT age;
    strT name;
    strT country;

    Human(ageT a, strT n, strT c)
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
    Human<int, string> firsthuman(10, "Tenzing", "Australia");
    firsthuman.print_details();

    return 0;
}