#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm>

#include "Case.h"
#include "List.h"
#include <algorithm>
using namespace std;

class Adapter
{
	string _str;

public:
	string ConvectionToFile(const List& list){
		_str.clear();
		string strTemp = " ; ";
		_str.append(list.getName());
		_str.append(strTemp);
		_str.append("\n{\n");
		
		for (size_t i=0; i < list.getVector().size(); i++) {
			
			_str.append(list.getVector()[i].getName());
			_str.append(strTemp);
			_str.append(list.getVector()[i].getTag());
			_str.append(strTemp);
			_str.append(to_string(list.getVector()[i].getPriorite()));
			_str.append(strTemp);
			_str.append(list.getVector()[i].getDate());
			_str.append(strTemp);
			_str.append(list.getVector()[i].getClarification());
			_str.append(strTemp);
			_str.append("\n");
		}
		_str.append(" }\n");
		return _str;
	}
	vector<List> ConvectionToList( string str) {
		vector<List> _list;
		int countList = std::count(str.begin(), str.end(), '{');
		string word;          //Буфер для считывания строки
		stringstream x;        //Создание потоковой переменной
		x << str;
		
		bool temp=false;
		for (size_t i = 0; i < countList; i++) {
			string nameList;
			while (true) {
				x >> word;
			
				if (word == ";") {
					break;
				}
		
				nameList.append(word);
				nameList.append(" ");
			}
			
				_list.push_back(nameList);
				x >> word;
				while (true) {
					string name; string tag; size_t priorite;
					string date; string clarification;
				while (true) {
					x >> word;
					if (word == "}") {
						temp = true;
						break;
					}
					if (word == ";") {
						break;
					}
				
					name.append(word);
					name.append(" ");
				}
				if (temp) {
					temp = false;
					break;
				}
				x >> word;
				tag = word;
				x >> word;
				x >> word;
				priorite = atoi(word.c_str());
				x >> word;
				while (true) {
					x >> word;
					if (word == ";") {
						break;
					}
					date.append(word);
					date.append(" ");
				}
				while (true) {
					x >> word;
					if (word == ";") {
						break;
					}
					clarification.append(word);
					clarification.append(" ");
				}
				_list[i].addCase(name, tag, priorite, date, clarification);	
			}		
		}
		return _list; 
	}
};

