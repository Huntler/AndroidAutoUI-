#include "include/system/SettingsManager.h"

#include <json/json.h>

#include <fstream>
#include <iostream>

void SettingsManager::readFile()
{
    // open the file
    std::ifstream file;
    file.open("file.txt");

    // initialize a datalist to store all the information
    std::list<std::string> datalist;

    if (file.is_open())
    {
        std::string line;

        // iterating through the file
        while (std::getline(file, line))
        {

            // append a line to the list of QStrings in the header file
            datalist.push_back(line);
        }

        // iterate over the list
        for (std::list<std::string>::iterator i = datalist.begin(); i != datalist.end(); i++)
        {
            std::cout << *i << "\n";
        }
    }

    else
    {
        std::cout << "file cannot be opened";
    }
}

void writeFile(std::string str)
{

}
