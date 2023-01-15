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
	//����������� �������� �����
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//��������� ����� ������ �� �������
	cout << "\x1b[32m";

	cout << "�������� ��������? ";
	string answer;
	cin >> answer;

	transform(answer);
	if (answer == "��")
		breaking(5);

	//��������� ����� ������ �� �����
	cout << "\x1b[0;37m";
	return 0;
}

//������� � ������ �������
void transform(string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= '�' && str[i] <= '�')
			str[i] += '�' - '�';
	}
}

//������ ��������
void breaking(int coef)
{
	srand((unsigned)time(0));
	cout << endl << endl;
	cout << "������� ������. . ." << endl;
	int cnt = 0;
	for (cnt = 0; cnt <= 100; cnt += (rand() % 10) + 1)
	{
		if (cnt > 95) cnt = 100;

		cout << "\r" << setw(3) << cnt << "% |";
		//��������� ����� ������� �� �������
		cout << "\x1b[42m";
		for (int i = 0; i < cnt * coef / 10; i++)
			cout << " ";
		//��������� ����� ������� �� ������
		cout << "\x1b[40m";
		for (int i = cnt * coef / 10; i < 10 * coef; i++)
			cout << " ";
		cout << "|";

		Sleep(300);
	}

	cout << endl << endl << endl << "�� ���� ��� �������, ������ �� ������� ����������. . .\n";
}