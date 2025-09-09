#include <iostream>
#include "../include/parser.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;

using namespace StringUtils;

string name;
string email;

int main()
{
    // Get the full name
    cout << "Enter both first and last name: ";
    string name;
    std::getline(cin, name);
    // Then the email
    cout << "Now enter your email: ";
    string email;
    std::getline(cin, email);

    string *firstName = new string;
    string *lastName = new string;

    parseName(name, firstName, lastName);
    string username = getUsername(email);

    cout << *firstName << endl;
    cout << *lastName << endl;
    cout << username << endl;
}
