#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <ctime> 

using namespace std;

void transform(string& str);
void breaking(int coef);

int main()
{
	//Подключение русского языка
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Изменения цвета текста на зеленый
	cout << "\x1b[32m";

	cout << "Взломать Пентагон? ";
	string answer;
	cin >> answer;

	transform(answer);
	if (answer == "да")
		breaking(5);

	//Изменения цвета текста на белый
	cout << "\x1b[0;37m";
	return 0;
}

//Перевод в нижний регистр
void transform(string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'А' && str[i] <= 'Я')
			str[i] += 'а' - 'А';
	}
}

//Полоса загрузки
void breaking(int coef)
{
	srand((unsigned)time(0));
	cout << endl << endl;
	cout << "Процент взлома. . ." << endl;
	int cnt = 0;
	for (cnt = 0; cnt <= 100; cnt += (rand() % 10) + 1)
	{
		if (cnt > 95) cnt = 100;

		cout << "\r" << setw(3) << cnt << "% |";
		//Изменение цвета консоли на зеленый
		cout << "\x1b[42m";
		for (int i = 0; i < cnt * coef / 10; i++)
			cout << " ";
		//Изменение цвета консоли на черный
		cout << "\x1b[40m";
		for (int i = cnt * coef / 10; i < 10 * coef; i++)
			cout << " ";
		cout << "|";

		Sleep(300);
	}

	cout << endl << endl << endl << "За Вами уже выехали, никуда не уходите пожалуйста. . .\n";
}