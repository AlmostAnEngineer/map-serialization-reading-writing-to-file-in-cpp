#include <unordered_map>
#include <fstream>
#include <iostream>

struct someData
{
    std::string dataname;
};

int main()
{
    using Map = std::unordered_map<int, someData>; // we gonna use it :)
    Map map;

    /*
                    READING DATA
    */
    if (std::filesystem::exists("data.dat")) //If file exist we gonna read the data.
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
    /*
    Adding some custom data and reading it
    */
    map[1].dataname = std::string("someName");
    for (auto [key, value] : map)
    {
        std::cout << key << " " << value.dataname << std::endl;
    }
    /*
         SAVE TO FILE
    */
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
