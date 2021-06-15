#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
#include <fstream>
using namespace std;
// typedef MULTI_MAP::iterator ITERATOR;
int main()
{

    std::map<string, string> Birthday;
    string key_name, key_lastName, b_day_value;
    string name_searched;

    // std::map<string, string>::iterator pos;
    //Redaing from a file
    ifstream file;
    file.open("data.txt", ios::in | ios::app | ios::binary);
    if (file.is_open())
    {
        cout << "File successfully opened!" << endl;
        while (!file.eof())
        {
            file >> key_name >> key_lastName >> b_day_value;
            string name = (key_name + " " + key_lastName);
            Birthday.insert(std::pair<string, string>(name, b_day_value));
        }
    }
    else
    {
        cout << "Unable to open file." << endl;
    }

    // cout << "Birthday list" << endl;
    // for (pos = Birthday.begin(); pos != Birthday.end(); pos++)
    // {
    //     cout << pos->first << " " << pos->second << endl;
    // }

    file.close();
    do
    {

        cout << "Search for somebody's birthday or type quit to stop the search." << endl;
        getline(std::cin, name_searched);
        if (name_searched == "quit")
        {
            break;
        }
        else
        {
            if (Birthday.find(name_searched) != Birthday.end())
            {
                cout << Birthday[name_searched] << endl;
            }
            else
            {
                cout << "The data of that person does not exist in the file!" << endl;
            }
        }
    }while(true);
    return 0;
}
