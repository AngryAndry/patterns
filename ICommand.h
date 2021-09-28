#pragma once
#include "Case.h"
#include "List.h"
#include "Application.h"
#include "File.h"
#include "Adapter.h"
class ICommand
{
protected:
	Application* _myApp=&Application::instance();
public :
	virtual ~ICommand() {}
	virtual void execute() = 0;

};

class CreatListCommand :public ICommand {	
	string _name;
public:
	CreatListCommand(const string& name) :_name(name) {

	}
	void execute() {
		_myApp->creatList(_name);
	}
};
class CreatCaseCommand :public ICommand {
	size_t _i;
	string _name;
	string _tag;
	int _priorite;
	string _date;
	string _clarification;
public:
	CreatCaseCommand(const size_t i, const string& name, const string& tag, const int priorite,
		const string& date, const string& clarification) :_i(i), _name(name), _tag(tag), _priorite(priorite),
		_date(date), _clarification(clarification) {}
	void execute() override {
		_myApp->creatCase(_i, _name, _tag, _priorite, _date, _clarification);
	}
};
class DeleteCaseCommand :public ICommand {
	size_t _posList;
	size_t _posCase;
public:
	DeleteCaseCommand(const size_t posList, const size_t posCase):_posList(posList),_posCase(posCase){}
	void execute() override{
		
		_myApp->deleteCase(_posList, _posCase);
		
	}
};

class DeleteListCommand :public ICommand {
	size_t _posList;
public:
	DeleteListCommand(const size_t posList):_posList(posList){}
	void execute()override {
		_myApp->deleteList(_posList);
	}
};


class ChangeDateCommand :public ICommand {
	string _date;
	size_t _posList;
	size_t _posCase;
public:
	ChangeDateCommand(const string& date, const size_t posList, const size_t posCase):_date(date),
		_posList(posList),_posCase(posList){}
	void execute() {
		_myApp->_list[_posList]._case[_posCase].setDate(_date);
	}
};
class ChangeTagCommand :public ICommand {
	string _tag;
	size_t _posList;
	size_t _posCase;
public:
	ChangeTagCommand(const string& tag, const size_t posList, const size_t posCase):_tag(tag),
		_posList(posList),_posCase(posList){}
	void execute() {
		_myApp->_list[_posList]._case[_posCase].setTag(_tag);
	}
};
class ChangeNameCommand :public ICommand {
	string _name;
	size_t _posList;
	size_t _posCase;
public:
	ChangeNameCommand(const string& name, const size_t posList, const size_t posCase):_name(name),
		_posList(posList),_posCase(posList){}
	void execute() {
		_myApp->_list[_posList]._case[_posCase].setName(_name);
	}
};

class ChangePrioriteCommand :public ICommand {
	int _piorite;
	size_t _posList;
	size_t _posCase;
public:
	ChangePrioriteCommand(const int piorite, const size_t posList, const size_t posCase):_piorite(piorite),
		_posList(posList),_posCase(posList){}
	void execute() {
		_myApp->_list[_posList]._case[_posCase].setPriorite(_piorite);
	}
};


class ChangeClarificationCommand :public ICommand {
	string _clarification;
	size_t _posList;
	size_t _posCase;
public:
	ChangeClarificationCommand(const string& date, const size_t posList, const size_t posCase):_clarification(_clarification),
		_posList(posList),_posCase(posList){}
	void execute() {
		_myApp->_list[_posList]._case[_posCase].setClarification(_clarification);
	}
};


class  NameSearchCommand :public ICommand {
	string _name;
public:
	NameSearchCommand(const string& name):_name(name){}
	void execute() {
		vector <size_t> tempVector=	_myApp->nameSearch(_name);
		for (size_t i = 0; i < tempVector.size(); i++) {
			_myApp->getVector()[tempVector[i]].getVector()[tempVector[i + 1]].printCase();			
			i++;
		}
	}
};

class  DateSearchCommand :public ICommand {
	string _date;
public:
	DateSearchCommand(const string& date):_date(date){}
	void execute() {
		vector <size_t> tempVector=	_myApp->dateSearch(_date);
		for (size_t i = 0; i < tempVector.size(); i++) {
			_myApp->getVector()[tempVector[i]].getVector()[tempVector[i + 1]].printCase();			
			i++;
		}
	}
};

class  TagSearchCommand :public ICommand {
	string _tag;
public:
	TagSearchCommand(const string& tag):_tag(tag){}
	void execute() {
		vector <size_t> tempVector=	_myApp->tagSearch(_tag);
		for (size_t i = 0; i < tempVector.size(); i++) {
			_myApp->getVector()[tempVector[i]].getVector()[tempVector[i + 1]].printCase();			
			i++;
		}
	}
};

class  PrioriteSearchCommand :public ICommand {
	int _priorite;
public:
	PrioriteSearchCommand(const int priorite):_priorite(priorite){}
	void execute() {
		vector <size_t> tempVector=	_myApp->prioriteSearch(_priorite);
		for (size_t i = 0; i < tempVector.size(); i++) {
			_myApp->getVector()[tempVector[i]].getVector()[tempVector[i + 1]].printCase();			
			i++;
		}
	}
};






class Invoker
{
	vector<ICommand*> DoneCommands;
	ICommand* command;
public:
	
	void save() {
		Adapter a;
		string t;
		for (size_t i = 0; i < Application::instance().getVector().size(); i++) {

			t.append((a.ConvectionToFile(Application::instance().getVector()[i])));
		}
		File::saveFile(t);
	}

	void load() {

		Adapter a;
		Application::instance().setVector(a.ConvectionToList(File::loadFile()));
	}
	void creatList(const string& name)
	{
		command = new CreatListCommand(name);
		command->execute();
		DoneCommands.push_back(command);
	}
	
	void deleteCase(const size_t posList, const size_t posCase) {

		command = new DeleteCaseCommand(posList, posCase);
		command->execute();
		DoneCommands.push_back(command);
	}
	void deleteList(const size_t posList) {
		command = new DeleteListCommand(posList);
		command->execute();
		DoneCommands.push_back(command);
	}

	void creatCase(const size_t i, const string& name, const string& tag, const size_t priorite,
		const string& date, const string& clarification) {
		command = new CreatCaseCommand(i, name, tag, priorite, date, clarification);
		command->execute();
		DoneCommands.push_back(command);
	}

	void changeDate(const string& date, const size_t posList, const size_t posCase) {
		command = new ChangeDateCommand( date, posList, posCase);
		command->execute();
		DoneCommands.push_back(command);
	}
		void changeTag(const string& tag, const size_t posList, const size_t posCase) {
		command = new ChangeTagCommand( tag, posList, posCase);
		command->execute();
		DoneCommands.push_back(command);
	}
		void changeName(const string& name, const size_t posList, const size_t posCase) {
		command = new ChangeNameCommand( name, posList, posCase);
		command->execute();
		DoneCommands.push_back(command);
	}
		void changeClarification(const string& clarification, const size_t posList, const size_t posCase) {
		command = new ChangeClarificationCommand(clarification, posList, posCase);
		command->execute();
		DoneCommands.push_back(command);
	}
	
		void changePriorite(const size_t priorite, const size_t posList, const size_t posCase) {
			command = new ChangePrioriteCommand(priorite, posList, posCase);
			command->execute();
			DoneCommands.push_back(command);
		}



		void nameSearch(const string& name) {
			command = new NameSearchCommand(name);
			command->execute();
			DoneCommands.push_back(command);
		}

		void dateSearch(const string& date) {
			command = new DateSearchCommand(date);
			command->execute();
			DoneCommands.push_back(command);
		}

		void tagSearch(const string& tag) {
			command = new TagSearchCommand(tag);
			command->execute();
			DoneCommands.push_back(command);
		}

		void prioriteSearch(const size_t priorite) {
			command = new PrioriteSearchCommand(priorite);;
			command->execute();
			DoneCommands.push_back(command);
		}

		void printAll()  {		
			Application::instance().printAllList();
	}

		
	void printList(const size_t j) {
		for (size_t i = 0; i < Application::instance().getVector().size(); i++) {
			Application::instance().printList(j - 1);
		}
	}
	void printCase(const size_t posList, const size_t posCase) {
		Application::instance().getVector()[posList].getVector()[posCase].printCase();
	}

};