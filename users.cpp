#include <iostream>
#include "users.h"
#include "base.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void users::showdata()
{
   
    ifstream file("/etc/passwd");
    if (file.is_open())
    {
        std::cout << "file opened";
        std::string line;

        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            std::string uname, x, uid;
            std::getline(iss, uname, ':');
            std::getline(iss, x, ':');
            std::getline(iss, uid, ':');
            cout << uid << " " << uname << endl;
        }
        file.close();
    }
    else
    {
        std::cout << "unable to open file";
    }
}
