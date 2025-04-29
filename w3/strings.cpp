#include <iostream>
#include <string>
using namespace std;

string firstname = "Mingma";
string lastname = "Sherpa";
string fullname = firstname + lastname;
string friendname;

int main()
{

    cout << fullname;

    cout << firstname.append(lastname);

    cout << firstname[0];

    cout << "enter the your friend name";
    cin >> friendname;
    cout << "Your friend name is : " << friendname << "\n";

    return 0;
}