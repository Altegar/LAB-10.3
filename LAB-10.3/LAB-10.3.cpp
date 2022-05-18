// LAB-9.3.cpp
// Сушинський Ігор
// Лабораторія №9.3
// Опрацювання масиву структур.
// Варіант 18

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці

using namespace std;

struct Price
{
	string tovar;
	string shop;
	float price;
};

void CreateTXT(Price* p, const int N, char* fname);
void PrintTXT(Price* p, const int N, char* fname);
void SearchPriceTXT(Price* p, const int N, char* fname);

int main()
{
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	// текстові файли
	char fname[100]; // ім'я першого файлу
	cout << "Ввести ім'я файлу: "; cin >> fname;

	int N;
	cout << "Введіть кількість товарів N: "; cin >> N;

	Price* p = new Price[N];

	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - вивід інформації про товар" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			CreateTXT(p, N, fname);
			break;
		case 2:
			PrintTXT(p, N, fname);
			break;
		case 3:
			SearchPriceTXT(p, N, fname);
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
	return 0;
}

void CreateTXT(Price* p, const int N, char* fname)
{
	ofstream fout(fname); // відкрили файл для запису

	for (int i = 0; i < N; i++)
	{
		cout << "Товар № " << i + 1 << ":" << endl;

		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

		cout << " назва товару: "; getline(cin, p[i].tovar); fout << p[i].tovar << endl; // записали його у файл
		cout << " назва магазину: "; getline(cin, p[i].shop); fout << p[i].shop << endl; // записали його у файл
		cout << " вартість товару: "; cin >> p[i].price; fout << p[i].price << endl; // записали його у файл
		cout << endl;
	}
}

void PrintTXT(Price* p, const int N, char* fname)
{
	ifstream fin(fname); // відкрили файл для зчитування

	cout << "=========================================="
		 << endl;
	cout << "|  №  |   Товар   |  Магазин  | Вартість |"
		 << endl;
	cout << "------------------------------------------"
		 << endl;

	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1;
		cout << " | " << setw(9) << right << p[i].tovar
			 << " | " << setw(9) << right << p[i].shop
			 << " | " << setw(8) << right << p[i].price << " |";
		cout << endl;
	}
	cout << "=========================================="
		 << endl;
	cout << endl;
}

void SearchPriceTXT(Price* p, const int N, char* fname)
{
	fstream fin(fname);

	string tovar;
	int k = 0;

	cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
	cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

	cout << " назва товару: "; getline(cin, tovar);

	for (int i = 0; i < N; i++)
	{
		k++;
		if (p[i].tovar == tovar)
		{
			cout << "=========================================="
				 << endl;
			cout << "|  №  |   Товар   |  Магазин  | Вартість |"
				 << endl;
			cout << "------------------------------------------"
				 << endl;
			cout << "| " << setw(3) << k << " | " << setw(9) << p[i].tovar << " | "
				 << setw(9) << p[i].shop << " | " << setw(8) << p[i].price << " |"
				 << endl;
			cout << "=========================================="
				 << endl;
			cout << endl;
		}
	}
}