#include <iostream>
#include "Stack.h"
#include <fstream>
#include <cstdio>

using namespace std;
void fileRead(Stack<int>& steck, string filename);
void fileSave(Stack<int>& steck, string filename);
int rand(int begin, int end);
void randFill(Stack<int>& steck, int n, int begin, int end);
void print(Stack<int>& steck);


void fileRead(Stack<int>& steck, string filename)
{
	int buff;
	ifstream fin(filename);
	while (!fin.eof())
	{
		fin >> buff;
		steck.push(buff);
	}
}

void fileSave(Stack<int>& steck, string filename)
{
	ofstream fout(filename);
	Stack<int>::iterator it = steck.GetBegin();
	if (!fout || steck.isEmpty())
	{
		cerr << "���� �� ����� ���� ������ ��� ���� ����!" << endl;
		exit(1);
	}
	while (it != nullptr)
	{
		fout << steck.GetValue(it) << " ";
		it = steck.GetNext(it);
	}
	cout << endl;
}

int rand(int begin, int end)
{
	return begin + rand() % (end - begin);
}

void randFill(Stack<int>& steck, int n, int begin, int end)
{
	srand(time(NULL));
	for (int i = 0; i < n; ++i) steck.push(rand(begin, end));
}


void print(Stack<int>& steck)
{
	Stack<int>::iterator it = steck.GetBegin();
	while (it != nullptr)
	{
		cout << steck.GetValue(it) << " ";
		it = steck.GetNext(it);
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "RU");
	Stack<int> steck;
	int selected = 0;
	int data;
	int count, begin, end;
	string filename;
	do
	{
		cout << "\t����\n"
			<< "1.�������� �������\n"
			<< "2.������� �������\n"
			<< "3.�������� ������ �������\n"
			<< "4.������� � ��������� � ���������� ����������\n"
			<< "5.������� �� �����\n"
			<< "6.������� � ����\n"
			<< "7.������� �� �������\n"
			<< "8.��������\n"
			<< "9.����� ������� �� ��������\n"
			<< "10.��������� �� �������\n"
			<< "11.������ ���������� ���������\n"
			<< "0.�����\n";
		if (cin >> selected)
		{
			switch (selected)
			{
			case 1:
				cout << "������� �������� ��������\n";
				cin >> data;
				steck.push(data);
				cout << "������� ��������\n";
				break;
			case 2:
				try
				{
					steck.pop();
					cout << "������� ������\n";
				}
				catch (exception ex)
				{
					cout << ex.what() << "\n";
				}
				break;
			case 3:
				try
				{
					cout << "������ �������: " << steck.top() << "\n";
				}
				catch (exception ex)
				{
					cout << ex.what() << "\n";
				}
				break;
			case 4:
				cout << "������� ���������� ���������\n";
				cin >> count;
				cout << "������� ������ ���������\n";
				cin >> begin;
				cout << "������� ����� ���������\n";
				cin >> end;
				randFill(steck, count, begin, end);
				break;
			case 5:
				cout << "������� ��� �����\n";
				cin >> filename;
				try
				{
					fileRead(steck, filename);
					cout << "���� ������\n";
				}
				catch (exception ex)
				{
					cout << ex.what() << "\n";
				}
				break;
			case 6:
				cout << "������� ��� ����� � �����������\n";
				cin >> filename;
				try
				{
					fileSave(steck, filename);
					cout << "�������� � ���� �������\n";
				}
				catch (exception ex)
				{
					cout << ex.what() << "\n";
				}
				break;
			case 7:
				if (!steck.isEmpty())
				{
					cout << "��������: ";
					print(steck);
				}
				else
				{
					cout << "���� ����\n";
				}
				break;
			case 8:
				steck.clear();
				cout << "������� �������\n";
				break;
			case 9:
				cout << "������� ��������\n";
				cin >> data;
				cout << steck.parse(data) << endl;
				break;
			case 10:
				if (steck.isEmpty())
				{
					cout << "����\n";
				}
				else
				{
					cout << "�� ����\n";
				}
				break;
			case 11:
				cout << "� ������ " << steck.GetSize() << " ���������\n";
				break;
			default:
				cout << "������� �����������\n";
				break;
			case 0:
				break;
			}
		}
		else
		{
			cout << "������� �����������\n";
		}
		system("pause");
		cout << "\n";
	} while (selected != 0);
	return 0;
}