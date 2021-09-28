#pragma once
#include "Case.h"
#include "Builder.h"
#include <vector>
#include <iostream>

using namespace std;
class List
{
private:
	string _name;
	
public:
	vector<Case> _case;
	List(string name) :_name(name) {
		 
	}
	List(const List& other):_name(other._name),_case(other._case) {
	}
	
	void setVector(vector<Case> otherCase) {
		_case = otherCase;
	}
	void addCase(const string& name, const string& tag, const int priorite,
		const string& date, const string& clarification) {
		ConcreteBuilder builder;
		builder.CreateProduct();
		builder.BuildName(name);
		builder.BuildTag(tag);
		builder.BuildPiorite(priorite);
		builder.BuildDate(date);
		builder.BuildClarification(clarification);

		_case.push_back(*builder.GetResult());
		delete builder.GetResult();
	}
	void eraseCase(const size_t i) {
		_case.erase(_case.begin()+i);
	}
	void changeCase(const size_t i, const string& name,
		const string& tag, const int priorite, const string& date, const string& clarification) {
		_case[i].setName(name);
		_case[i].setTag(tag);
		_case[i].setPriorite(priorite);
		_case[i].setDate(date);
		_case[i].setClarification(clarification);

	}
	void changeTag(const string& tag, const size_t posCase) {
		_case[posCase].setTag(tag);
	}void changeName(const string& name, const size_t posCase) {
		_case[posCase].setName(name);
	}void changePriorite(const size_t priorite, const size_t posCase) {
		_case[posCase].setPriorite(priorite);
	}void changeDate(const string& date, const size_t posCase) {
		_case[posCase].setDate(date);
	}void changeClarification(const string& clarification, const size_t posCase) {
		_case[posCase].setClarification(clarification);
	}
	void printList() {
		size_t j = 0;
		for (auto i : _case) {
			j++;
			cout << "¹" << j<<endl;
			i.printCase();
		}
	}
	string getName()const {
		return _name;
	}
	void setName(const string& name) {
		_name = name;
	}
	vector<Case> getVector()const {
		return _case;
	}
	vector<Case> deleteCase(const size_t i) {
		_case.erase(_case.begin()+i);
		return _case;
	}
};

