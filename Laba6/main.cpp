#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "mystructs.h"
#include "constants.h"
#include "myfuncs.h"
using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string _name{}, _count{}, _volume{};
	list data{}, empty{}, selectedData{};
	data = data.fileInput();
	while (true) {
		int point{ menu() };
		if (point == 1) 
			data.print();
		if (point == 2) {
			int select{ selectionMenu() };
			if (select == 1) {
				cout << "Введите значение элемента,который хотите удалить: " << endl;
				cin >> _name;
				data.remove1(_name);
			}
			if (select == 2) {
				cout << "Введите значение элемента,который хотите удалить: " << endl;
				cin >> _count;
				data.remove2(_count);
			}
			if (select == 3) {
				cout << "Введите значение элемента,который хотите удалить: " << endl;
				cin >> _volume;
				data.remove3(_volume);
			}


		}
		if (point == 3) {
			data = empty;
			_name = DEFAULT_LIST.name;
			_count = DEFAULT_LIST.count;
			_volume = DEFAULT_LIST.volume;
			data.add_item(_name, _count, _volume);
		}
		if (point == 4)
			break;		
	}
	data.fileOutput();

}

