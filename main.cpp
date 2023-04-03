#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <thread>
#include <dirent.h>
#include "base.h"
#include "users.h"
#include "processes.h"

using namespace std;

int main()
{

    ifstream file("config.txt");
    string line;
    int userTime = 0;
    int processTime = 0;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            istringstream iss(line);
            string key, value;
            iss >> key >> value;
            if (key == "users:")
            {
                userTime = stoi(value);
            }
            if (key == "processes:")
            {
                processTime = stoi(value);
            }
        }
    }

    base* user = new users();
    base* process = new processes();
    auto start = chrono::steady_clock::now();
    int sec,lastsec=-1;
    while (true)
    {
            auto end = chrono::steady_clock::now();
            sec = chrono::duration_cast<chrono::seconds>(end - start).count();
        if (userTime > 0 && sec%userTime==0 && sec!=0 && sec!=lastsec)
        {
            if(sec%userTime==0 && sec!=0 && sec!=lastsec)
            // cout<<sec<<endl;
            std::cout << "Users Data:" << endl
                      << "User Id    User Name" << endl;
            user->showdata();
            cout<<"Printed user data"<<endl;
        }
        if (processTime > 0 && sec%processTime==0 && sec!=lastsec)
        {
            this_thread::sleep_for(chrono::milliseconds(processTime));
            // cout<<sec<<endl;

            cout << "Processes Data:" << endl
                 << "Process Id    Process Name" << endl;
            process->showdata();
            cout<<"Pronted Process Data"<<endl;
        }
        lastsec = sec;
    }
    return 0;
}
