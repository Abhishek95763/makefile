#include "processes.h"
#include <dirent.h>
#include <fstream>
#include <sstream>
#include <string>

void processes::showdata()
{
    // cout<<"processes";
    DIR *dir = opendir("/proc");
    if (dir == NULL)
    {
        std::cout << "Unable to open directory:";
    }
    else
    {
        struct dirent *entity;
        entity = readdir(dir);
        while (entity != NULL)
        {
            bool is_process = true;
            std::string filename = entity->d_name;
            for (auto &ch : filename)
            {
                if (!isdigit(ch))
                {
                    is_process = false;
                    break;
                }
            }
            if (is_process)
            {
                std::string filedir = "/proc/" + filename + "/status";
                std::ifstream status_file(filedir);
                std::string line;
                while (std::getline(status_file, line))
                {
                    std::istringstream iss(line);
                    std::string key, value;
                    iss >> key >> value;
                    if (key == "Name:")
                    {
                        cout << filename << " " << value << endl;
                    }
                }
            }
            entity = readdir(dir);
        }
    };
}