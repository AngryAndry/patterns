
/*
* В экзаменационной работе реальзовал несколько паттернов:
* 1 Строитель - используется для создания "дел"
* 2 Адаптер - он переводит Case в строку и наоборот  для сохранения\загрузки в фаил
* 3 Команда - инкапсулирует данные приложения и дает возможность управления им
* 4 Синглтон - заключенно само приложение класс "Application"
* 
* 
* тестирование было проведино только методом "белого ящика"
* так как на "черный "необходимо было бы прописовать огромное количество исключений
* 
* 
*/#include <iostream>
#include <windows.h>

#include "Application.h"
#include "ICommand.h"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Invoker inv;
	cout << "****Планировщик задач****" << endl;
	cout << "Загрузить список дел с фаила?\n 1 - да , 0 - нет" << endl;
	int i = 0;
	string date;
	string tag;
	int priorite;
	string name;
	string clarification;
	string str;
	cin >> i;
	if (i) {
		inv.load();
	}
	else {
		cout << "Введите название нового списка: ";
		cin.ignore();
		cin.clear();
		getline(cin, name);
		inv.creatList(name);
		cout  << endl;
	}
	system("cls");
	while (true) {
		cout << "Список дел:" << endl;
		inv.printAll();
		size_t j = 0;
		size_t posList = 0;
		size_t z = 0;
		cout << "Меню:" << endl;
		cout << "0 - выбрать список" << endl;
		cout << "1 - добавить список" << endl;
		cout << "2 - удалить список" << endl;
		cout << "3 - сохранить все" << endl;
		cout << "4 - меню поиска" << endl;
		cout << "5 - выйти из приложения" << endl;
		cin >> j;
		system("cls");

		switch (j)
		{
		case 0:
			inv.printAll();
			cout << "Введите номер списка:" << endl;
			cin >> j;
			posList = j;
			inv.printList(j);
			cout << "0 - выбрать дело" << endl;
			cout << "1 - добавить дело" << endl;
			cout << "2 - удалить дело" << endl;
			cout << "3 - выход в главное меню" << endl;
			cin >> j;
			switch (j)
			{
			case 0:
				system("cls"); 
				inv.printList(posList);
				cout << "Введите номер дела:" << endl;
				cin >> z;
				inv.printCase(posList - 1, z - 1);
				cout << "0 - изменить имя дела" << endl;
				cout << "1 - изменить тег дела" << endl;
				cout << "2 - изменить приоритет дела" << endl;
				cout << "3 - изменить дату дела" << endl;
				cout << "4 - изменить описание дела" << endl;
				cout << "5 - выход в главное меню" << endl;
				cin >> j;
				switch (j)
				{
				case 0:
					system("cls");
					cout << "Введите новое имя" << endl;
					cin.ignore();
					cin.clear();
					getline(cin, str);
					inv.changeName(str, posList - 1, z - 1);
					break;
				case 1:
					system("cls");
					cout << "Введите новый тег" << endl;
					cin.ignore();
					cin.clear();
					getline(cin, str);
					inv.changeTag(str, posList - 1, z - 1);
					break;
				case 2:
					system("cls");
					cout << "Введите новый приоритет" << endl;
					cin.ignore();
					cin.clear();
					cin >> j;
					inv.changePriorite(j, posList - 1, z - 1);
					break;
					system("cls");
				case 3:
					cout << "Введите новое описание" << endl;
					cin.ignore();
					cin.clear();
					getline(cin, str);
					inv.changeClarification(str, posList - 1, z - 1);
					break;
				default:
					break;
				}
				break;
			case 1:
				system("cls");
				inv.printList(j);
				cin.ignore();
				cin.clear();
				cout << "\"-1\"  - для отмены"<<endl;
				cout << "Введите имя нового дела: ";
				
				getline(cin, name);
				if (name == "-1") {
					break;
				}
				system("cls");
				cout << "\"-1\"  - для отмены"<<endl;
				cout << "Введите тег нового дела: ";
				getline(cin, tag);
				if (tag == "-1") {
					break;
				}
				system("cls");
				cout << "\"-1\"  - для отмены"<<endl;
				cout << "Введите приоритет нового дела: "; 
				cin >> priorite;
				cin.ignore();
				if (priorite == -1) {
					break;
				}
				cin.clear();
				system("cls");
				cout << "\"-1\"  - для отмены"<<endl;
				cout << "Введите дату нового дела: "; 
				getline(cin, date);
				if (date == "-1") {
					break;
				}
				system("cls");
				cout << "\"-1\"  - для отмены"<<endl;
				cout << "Введите описание нового дела: ";
				getline(cin, clarification);
				system("cls");
				if (clarification == "-1") {
					break;
				}
				inv.creatCase(posList - 1, name, tag, priorite, date, clarification);
				system("cls");
				cout << endl;

				break;


			case 2:
				system("cls");
				inv.printList(posList);
				cout << "Удаление дела:" << endl;
				cout << "Введите номер дела:" << endl;
				cin >> z;
				inv.deleteCase(posList - 1, z - 1);
				break;
			case 3:
				break;
			default:
				break;
			}
			break;
		case 1:
			system("cls");
			cout << "Введите название нового списка: ";
			cin.ignore();
			cin.clear();
			getline(cin, name);
			inv.creatList(name);
			cout << endl;
			break;

		case 2:
			system("cls");
			inv.printAll();
			cout << "Введите номер списка: ";
			cin >> j;
			inv.deleteList(j);
			break;
		case 3:
			inv.save();
			break;
		case 4:
			system("cls");
			cout << "Почему будет производиться поиск?" << endl;
			cout << "0 - имя дела" << endl;
			cout << "1 - тег дела" << endl;
			cout << "2 - приоритет дела" << endl;
			cout << "3 - дата дела" << endl;
			cout << "4 - выход в главное меню" << endl;
			cin >> j;
			switch (j)
			{
			case 1:
				system("cls");
				cin.ignore();
				cin.clear();
				cout << "Введите тег: ";
				getline(cin, tag);

				inv.tagSearch(tag);
				break;
			case 2:
				system("cls");
				cin.ignore();
				cin.clear();
				cout << "Введите приоритет: ";
				cin >> j;

				inv.prioriteSearch(j);
				break;
			case 0:
				system("cls");
				cin.ignore();
				cin.clear();
				cout << "Введите имя: ";
				getline(cin, name);

				inv.nameSearch(name.append(" "));
				break;
			
			
			case 3:
				system("cls");
				cin.ignore();
				cin.clear();
				cout << "Введите дату: ";
				getline(cin, date);

				inv.dateSearch(date);
				break;
			case 4 :
				break;
			default:
				break;
			}
			break;
		case 5 :
			exit(0);

		}
	}
	return 0;
}
