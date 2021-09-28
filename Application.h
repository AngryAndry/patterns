#pragma once
#include <vector>
#include <iostream>
//#include "ICommand.h"
#include"List.h"
using namespace std;
class Application
{
private:
	Application() {

	}
	
public:
	vector<List> _list;
	Application(Application& other) = delete;
	void operator=(const Application&) = delete;
	static Application& instance() {
		static Application inst;
		return inst;
	}
	//friend ICommand;
	void creatList(const string& name) {
		List list(name);
		_list.push_back(list);
	}
	void printAllList(){
		size_t j = 0;
		for (auto i :_list)
		{
			j++;
			cout<<j<<" "<<i.getName()<<endl;
		}
	}
	void printList(const size_t i) {

		cout <<"Список :  "  <<_list[i].getName() << endl<< endl;
		_list[i].printList();
	}
	void creatCase(const size_t i , const string& name, const string& tag, const size_t priorite,
		const string& date, const string& clarification) {
		_list[i].addCase(name,tag,priorite,date, clarification);
	}
	vector<List> getVector()const {
		return _list;
	}
	void setVector(vector<List> list) {
		_list = list;
	}
	void deleteList(const size_t posList) {
		_list.erase(_list.begin() + posList-1);
	}

	void deleteCase(const size_t posList, const size_t posCase) {
		_list[posList].deleteCase(posCase);
		
	}

	void changeTag(const string& tag, const size_t posList, const size_t posCase) {
		_list[posList].changeTag(tag,posCase);
	}	void changeName(const string& name, const size_t posList, const size_t posCase) {
		_list[posList].changeName(name,posCase);
	}	void changeDate(const string& date, const size_t posList, const size_t posCase) {
		_list[posList].changeDate(date,posCase);
	}	void changePriorite(const int priorite, const size_t posList, const size_t posCase) {
		_list[posList].changePriorite(priorite,posCase);
	}	void changeClarification(const string& clarification, const size_t posList, const size_t posCase) {
		_list[posList].changeClarification(clarification,posCase);
	}
	vector <size_t> nameSearch(const string& name) {
		
		vector <size_t> listCoordinates;
		size_t coordinates;
		for (size_t i = 0; i < _list.size(); i++)
		{
			for (size_t j = 0; j < _list[i].getVector().size(); j++)
			{
				if (name._Equal( _list[i].getVector()[j].getName())) {
				
					listCoordinates.push_back(i);
					listCoordinates.push_back(j);
				}
			}
		}
		return listCoordinates;
	}
	vector <size_t> dateSearch(const string& date) {

		vector <size_t> listCoordinates;
		size_t coordinates=0;
		for (size_t i = 0; i < _list.size(); i++)
		{
			for (size_t j = 0; j < _list[i].getVector().size(); j++)
			{
				if (date == _list[i].getVector()[j].getDate()) {

					listCoordinates.push_back(i);
					listCoordinates.push_back(j);
				}
			}
		}
		return listCoordinates;
	}
	vector <size_t> tagSearch(const string& tag) {

		vector <size_t> listCoordinates;
		size_t coordinates=0;
		for (size_t i = 0; i < _list.size(); i++)
		{
			for (size_t j = 0; j < _list[i].getVector().size(); j++)
			{
				if (tag._Equal(_list[i].getVector()[j].getTag())) {

					listCoordinates.push_back(i);
					listCoordinates.push_back(j);
				}
			}
		}
		return listCoordinates;
	}
	vector <size_t> prioriteSearch(int priorite) {

		vector <size_t> listCoordinates;
		size_t coordinates=0;
		for (size_t i = 0; i < _list.size(); i++)
		{
			for (size_t j = 0; j < _list[i].getVector().size(); j++)
			{
				if (priorite == _list[i].getVector()[j].getPriorite()) {

					listCoordinates.push_back(i);
					listCoordinates.push_back(j);
				}
			}
		}
		return listCoordinates;
	}
};

