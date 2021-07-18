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
		cerr << "Файл не может быть открыт или стек пуст!" << endl;
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
		cout << "\tМеню\n"
			<< "1.Добавить элемент\n"
			<< "2.Удалить элемент\n"
			<< "3.Получить данные вершины\n"
			<< "4.Создать и заполнить её рандомными элементами\n"
			<< "5.Считать из файла\n"
			<< "6.Вывести в файл\n"
			<< "7.Вывести на консоль\n"
			<< "8.Очистить\n"
			<< "9.Найти элемент по значению\n"
			<< "10.Проверить на пустоту\n"
			<< "11.Узнать количество элементов\n"
			<< "0.Выход\n";
		if (cin >> selected)
		{
			switch (selected)
			{
			case 1:
				cout << "Введите значение элемента\n";
				cin >> data;
				steck.push(data);
				cout << "Элемент добавлен\n";
				break;
			case 2:
				try
				{
					steck.pop();
					cout << "Элемент удален\n";
				}
				catch (exception ex)
				{
					cout << ex.what() << "\n";
				}
				break;
			case 3:
				try
				{
					cout << "Данные вершины: " << steck.top() << "\n";
				}
				catch (exception ex)
				{
					cout << ex.what() << "\n";
				}
				break;
			case 4:
				cout << "Введите количество элементов\n";
				cin >> count;
				cout << "Введите начало диапазона\n";
				cin >> begin;
				cout << "Введите конец диапазона\n";
				cin >> end;
				randFill(steck, count, begin, end);
				break;
			case 5:
				cout << "Введите имя файла\n";
				cin >> filename;
				try
				{
					fileRead(steck, filename);
					cout << "Файл считан\n";
				}
				catch (exception ex)
				{
					cout << ex.what() << "\n";
				}
				break;
			case 6:
				cout << "Введите имя файла с расширением\n";
				cin >> filename;
				try
				{
					fileSave(steck, filename);
					cout << "Выведено в файл успешно\n";
				}
				catch (exception ex)
				{
					cout << ex.what() << "\n";
				}
				break;
			case 7:
				if (!steck.isEmpty())
				{
					cout << "Элементы: ";
					print(steck);
				}
				else
				{
					cout << "Стек пуст\n";
				}
				break;
			case 8:
				steck.clear();
				cout << "Очищено успешно\n";
				break;
			case 9:
				cout << "Введите значение\n";
				cin >> data;
				cout << steck.parse(data) << endl;
				break;
			case 10:
				if (steck.isEmpty())
				{
					cout << "Пуст\n";
				}
				else
				{
					cout << "Не пуст\n";
				}
				break;
			case 11:
				cout << "В списке " << steck.GetSize() << " элементов\n";
				break;
			default:
				cout << "Команда отсутствует\n";
				break;
			case 0:
				break;
			}
		}
		else
		{
			cout << "Команда отсутствует\n";
		}
		system("pause");
		cout << "\n";
	} while (selected != 0);
	return 0;
}