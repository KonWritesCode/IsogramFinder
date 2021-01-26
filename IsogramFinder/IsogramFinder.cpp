// IsogramFinder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector<std::string> listOfIsograms{};

int main()
{
    std::fstream fileListOfWords("ListOfWords.txt", std::ios::in); // Reads
    std::fstream fileIsogram("Isograms.txt", std::ios::out); // Outputs
    std::string str;
    std::string file_contents;

    bool isIsogram{true};
    int num = 0;

    fileIsogram.clear();

    while (std::getline(fileListOfWords, str))
    {
        isIsogram = true;
        for (int i = 0; i < str.length(); i++) 
        {
            for (int j = i+1; j < str.length(); j++) 
            {
                if (str[i] == str[j]) {
                    isIsogram = false;
                }
            }
        }
        if (isIsogram == true)
        {
            fileIsogram << str << std::endl;
            std::cout << str << std::endl;
        }
    }

    fileListOfWords.close();
    fileIsogram.close();
}
