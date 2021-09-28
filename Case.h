#pragma once
#include <string>
#include <iostream>
using namespace std;
class Case
{
private :
	string _date;
	string _tag;
	int _priorite;
	string _name;
	string _clarification;
public:
	Case():_name("None"), _tag("None"), _priorite(0), _date("00.00.0000") ,_clarification("NONE"){
	}
	string getDate()const {
		return _date;
	}
	string getTag()const {
		return _tag;
	}
	string getName()const {
		return _name;
	}
	int getPriorite()const {
		return _priorite;
	}
	string getClarification()const {
		return _clarification;
	}
	void setDate(const string& date) {
		_date = date;
	}	
	void setTag(const string& tag) {
		_tag = tag;
	}	
	void setName(const string& name) {
		_name = name;
	}	
	void setPriorite(const int priorite) {
		_priorite = priorite;
	}
	void setClarification(const string& clarification) {
		_clarification = clarification;
	}
	void printCase() {
		cout << "Имя :" << _name << endl << "Тег :" << _tag << endl <<
			"Приоритет :" << _priorite << endl << "Дата :" << _date << endl<<
			"Описание дела :"<< _clarification<<endl<<endl;
	}
};

