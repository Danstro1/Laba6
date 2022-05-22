#include <iostream>

using namespace std;

int menu() {
	int point{};
	while (true) {
		cout << "1.Печать всех элементов" << endl;
		cout << "2.Удаление всех элементов, заданных значением поля" << endl;
		cout << "3.Сброс значений всех элементов" << endl;
		cout << "4.Выход" << endl;
		cin >> point;
		if (point >= 1 && point <= 4)
			break;
		else  {
			cin.clear();
			cin.ignore(100500, '\n');
			cout << "Ошибка ввода" << endl;
		}	
	}
	return point;
}

int selectionMenu() {
	int select{};
	while (true) {
		cout << "1.Удаление элемента по названию ценной бумаги" << endl;
		cout << "2.Удаление элемента по количеству сделок" << endl;
		cout << "3.Удаление элемента по объёму торгов" << endl;
		cin >> select;
		if (select >= 1 && select <= 3)
			break;
		else {
			cin.clear();
			cin.ignore(100500, '\n');
			cout << "Ошибка ввода" << endl;
		}
	}
	return select;
}

