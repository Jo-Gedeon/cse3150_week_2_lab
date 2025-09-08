#include <iostream>
#include "../include/parser.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace StringUtils
{
    void parseName(const std::string &fullName, std::string *firstName, std::string *lastName)
    {
        string s = fullName;
        string delimeter = " ";
        *firstName = s.substr(0, s.find(delimeter));
        *lastName = s.substr(s.find(delimeter) + 1);
    }

    string getUsername(const std::string &email)
    {
        string e = email;
        string delimiter = "@";
        string user = e.substr(0, e.find(delimiter));
        return user;
    }

}
