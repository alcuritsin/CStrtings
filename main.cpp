#include<iostream>
 #include<Windows.h>
//using namespace std;

int StrLen(char str[]);

void main()
{
	setlocale(LC_ALL, "Russian");
	system("CHCP 1251");
	system("cls");
	//char str[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	//char str[] = "Hello";
	const int n = 20;
	char str[n];
	std::cout << "Введите строку: ";
	//SetConsoleCP(1251);
	//std::cin >> str;
	std::cin.getline(str, n);
	//SetConsoleCP(866);
	std::cout << str << std::endl;

	std::cout<< "Длинна строки: " << StrLen(str) << std::endl;

}

int StrLen(char str[])
{
	int n = 0;
	for (; str[n]; n++);
	std::cout << "n = "<< n << std::endl;

	int i = 0;
	do 
	{/*Ничиво не делаю :)*/} while (str[i++] != '\0');


	return --i;
}
