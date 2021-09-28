#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class File
{
public:
	 bool static saveFile(const string& dataFile) {
        ofstream out;          // ����� ��� ������
        out.open("List.txt"); // �������� ���� ��� ������
        if (out.is_open())
        {
            out << dataFile << endl;
            cout << "���� ��������" << endl;
            out.close();
            return true;
        }

       
        return 0;
	}
    string static loadFile() {
        string line;
        string dataFile;

        std::ifstream in("List.txt"); // �������� ���� ��� ������
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

