#include <iostream>

using namespace std;

int menu() {
	int point{};
	while (true) {
		cout << "1.������ ���� ���������" << endl;
		cout << "2.�������� ���� ���������, �������� ��������� ����" << endl;
		cout << "3.����� �������� ���� ���������" << endl;
		cout << "4.�����" << endl;
		cin >> point;
		if (point >= 1 && point <= 4)
			break;
		else  {
			cin.clear();
			cin.ignore(100500, '\n');
			cout << "������ �����" << endl;
		}	
	}
	return point;
}

int selectionMenu() {
	int select{};
	while (true) {
		cout << "1.�������� �������� �� �������� ������ ������" << endl;
		cout << "2.�������� �������� �� ���������� ������" << endl;
		cout << "3.�������� �������� �� ������ ������" << endl;
		cin >> select;
		if (select >= 1 && select <= 3)
			break;
		else {
			cin.clear();
			cin.ignore(100500, '\n');
			cout << "������ �����" << endl;
		}
	}
	return select;
}

