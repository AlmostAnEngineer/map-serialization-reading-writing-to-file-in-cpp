#include <unordered_map>
#include <fstream>
#include <iostream>
#include <filesystem>
struct someData
{
    std::string dataname;
};
using Map = std::unordered_map<int, someData>;
void printData(Map &map);
void readData(Map &map);
void addData(Map &map, int ID, std::string param);
void saveData(Map &map);

int main()
{
    Map map;
    readData(map);
    for (size_t i = 4; i < 1000000; i++)
    {
        addData(map, i, "name");
    }
    printData(map);
    saveData(map);
    return 0;
}
void printData(Map &map)
{
    for (auto [key, value] : map)
    {
        std::cout << key << " " << value.dataname << std::endl;
    }
}
void readData(Map &map)
{
    if (std::filesystem::exists("data.dat")) // If file exist we gonna read the data.
    {
        std::ifstream instream;
        instream.open("data.dat");
        int ID;
        std::string name;
        if (instream.is_open())
        {
            while (!instream.eof())
            {
                instream >> ID >> name;
                map[ID].dataname = name;
            }
            instream.close();
        }
        else
        {
            exit(1);
        }
    }
}

void addData(Map &map, int ID, std::string param)
{
    map[ID].dataname = param;
}

void saveData(Map &map)
{
    std::ofstream streamdata;
    streamdata.open("data.dat");
    if (streamdata.is_open())
    {
        for (auto [key, value] : map)
        {
            streamdata << key << " " << value.dataname << std::endl;
        }
        streamdata.close();
    }
    else
    {
        exit(1);
    }
}
