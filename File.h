#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class File
{
public:
	 bool static saveFile(const string& dataFile) {
        ofstream out;          // поток для записи
        out.open("List.txt"); // окрываем файл для записи
        if (out.is_open())
        {
            out << dataFile << endl;
            cout << "Фаил сохранен" << endl;
            out.close();
            return true;
        }

       
        return 0;
	}
    string static loadFile() {
        string line;
        string dataFile;

        std::ifstream in("List.txt"); // окрываем файл для чтения
        if (in.is_open())
        {
            while (getline(in, line))
            {
                dataFile.append(line);
                dataFile.append("\n");
                
            }
        }
        in.close();
        return dataFile;
    }
};

