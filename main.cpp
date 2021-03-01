#include<iostream>
 #include<Windows.h>
//using namespace std;

//TODO: 2021_02_26
/*
В проект CStrings добавить функции :
bool is_int_number(char str[]);	//Определяет, является ли строка целым числом.
int  to_int_number(char str[]);	//Если строка - целое число, то функция возвращает его значение.
bool is_bin_number(char str[]);	//Определяет, является ли строка Двоичным числом.
int  bin_to_dec(char str[]);	//Если строка - Двоичное число, то функция возвращает его десятичное значение.
bool is_hex_number(char str[]);	//Определяет, является ли строка Шестнадцатеричным числом.
int  hex_to_dec(char str[]);	//Если строка - Шестнадцатеричное число, то функция возвращает его десятичное значение.

//DONE: 2021_02_24
bool is_palindrome(char str[]);	//Определяет, является ли строка палиндромом. --done

//DONE: 2021_02_24
void to_upper(char str[]);	//переводит строку в верхний регистр --done
void to_lower(char str[]);	//переводит строку в нижний регистр --done
void capitalize(char str[]);	//первую букву каждого слова в предложении делает заглвыной --done
void shrink(char str[]);	//удаляет лишние пробелы из предложения, например: --done
				//Харашо      живет   на   свете          Винни Пух!
				//Харашо живет на свете Винни Пух!
*/

//#define CW_CSTRINGS_FIRST_MEET //Первое знакомство со строками
#define HW_CSTRINGS_2021_02_24 //Первое знакомство со строками

int StrLen(char str[]);			//Вычисляет длинну строки

void to_upper(char str[]);		//переводит строку в верхний регистр;
void to_lower(char str[]);		//переводит строку в нижний регистр;
void capitalize(char str[]);	//первую букву каждого слова в предложении делает заглвыной;
void shrink(char str[]);		//удаляет лишние пробелы из предложения;
void remove_symbol(char str[], char symbol); //Удаляет все вхождения символа

bool is_palindrome(char str[]);	//Определяет, является ли строка палиндромом.

void main()
{
	setlocale(LC_ALL, "Russian");
	system("CHCP 1251");
	system("CLS");

#ifdef CW_CSTRINGS_FIRST_MEET
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
#endif // CW_CSTRINGS_FIRST_MEET

#ifdef HW_CSTRINGS_2021_02_24
	//Проверочные строки:
	//char str[] = " абвгд е  ёжз ийклм н опр стуф хцч шщ ъыь эюя ";
	//char str[] = " ab cd e f g h i gk l m o p q rst uv wz y x ";
	//char str[] = " Харашо      живет   на   свете          Винни Пух!";
	//char str[] = "123321";
	//char str[] = "1234321";
	//char str[] = "123456";
	char str[] = "Аргентина манит негра";
 	
	/*
	const int n = 20;
	char str[n];
	
	std::cout << "Введите строку :";
	std::cin.getline(str, n);
	*/

	//Вывод в консоль начального варианта:
	//std::cout << "До реформации :";
	std::cout << str << std::endl;
	//std::cout<< "Длинна строки: " << StrLen(str) << std::endl;

	//Трансформация:
	//to_upper(str);	//переводит строку в верхний регистр;
	//to_lower(str);	//переводит строку в нижний регистр;
	//capitalize(str);	//первую букву каждого слова в предложении делает заглвыной;
	//shrink(str);		//удаляет лишние пробелы из предложения;

	//Вывод результата:
	//std::cout << "После реформации :";
	//std::cout << str << std::endl;

	//std::cout<< "Длинна строки: " << StrLen(str) << std::endl;

	if (is_palindrome(str))
	{
		std::cout << "Строка палиндром!" << std::endl;
	}
	else
	{
		std::cout << "Строка НЕ палиндром!" << std::endl;
	}
	std::cout << str << std::endl;

#endif // HW_CSTRINGS_2021_02_24
}

int StrLen(char str[])
{
	int n = 0;
	for (; str[n]; n++);
	//std::cout << "n = "<< n << std::endl;

	int i = 0;
	do 
	{/*Ничиво не делаю :)*/} while (str[i++] != '\0');

	return --i;
}

void to_upper(char str[])
{//переводит строку в верхний регистр;
//ASCII - magic
/*
en_US		a-z -> A-Z		97-122 -> 65-90		32
ru_RU		а-я -> А-Я		224-255 -> 192-223	32
ru_RU		ё -> Ё		241 -> 240				16
*/
	int i = 0;
	for (; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я')
		{//en_US		ru_RU
			str[i] -= 32;
		}
		else if (str[i] == 'ё')
		{//ru_RU
			str[i] -= 16;
		}
	}
}
void to_lower(char str[])
{//переводит строку в нижний регистр;
//ASCII - magic
/*
en_US		a-z -> A-Z		97-122 -> 65-90		32
ru_RU		а-я -> А-Я		224-255 -> 192-223	32
ru_RU		ё -> Ё		241 -> 240				16
*/
	int i = 0;
	for (; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'А' && str[i] <= 'Я')
		{//en_US		ru_RU
			str[i] += 32;
		}
		else if (str[i] == 'Ё')
		{//ru_RU
			str[i] += 16;
		}
	}
}
void capitalize(char str[])
{//первую букву каждого слова в предложении делает заглвыной;

	if (str[0] >= 'a' && str[0] <= 'z' || str[0] >= 'а' && str[0] <= 'я')
	{//en_US		ru_RU
		str[0] -= 32;
	}
	else if (str[0] == 'ё')
	{//ru_RU
	str[0] -= 16;
	}

	for (int i = 1; str[i]; i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я') && str[i-1] ==' ')
		{//en_US		ru_RU
			str[i] -= 32;
		}
		else if (str[i] == 'ё' && str[i-1] == ' ')
		{//ru_RU
		str[i] -= 16;
		}
	}

	/*
	int i = 0;
	//Первая буква в строке :)
	if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я')
	{//en_US		ru_RU
		str[i] -= 32;
	}
	else if (str[i] == 'ё')
	{//ru_RU
	str[i] -= 16;
	}

	for (; str[i]; i++)
	{
		if (str[i] == ' ')
		{
			if (!str[i + 1])
			{//если конец строки не пытаться посмотреть за массив
				return;
			}
			else if (str[i + 1] >= 'a' && str[i + 1] <= 'z' || str[i + 1] >= 'а' && str[i + 1] <= 'я')
			{//en_US		ru_RU
				str[i + 1] -= 32;
			}
			else if (str[i + 1] == 'ё')
			{//ru_RU
				str[i + 1] -= 16;
			}
		}
	}
	*/
}
void shrink(char str[])
{//удаляет лишние пробелы из предложения;
	while (str[0] == ' ') //Если начинается с пробела :) 1C-ка так любит
	{
		int i = 0;
		for (; str[i]; i++)
		{
			str[i] = str[i + 1];
		}
	}

	int i = 0; //В остальных случаях!!!
	for (; str[i]; i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
			i--; //Возврат корретки :D
		}
	}
}

void remove_symbol(char str[], char symbol)
{//Удаляет все вхождения символа
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++) str[j] = str[j + 1];
		}
	}
}

bool is_palindrome(char str[])
{//Определяет, является ли строка палиндромом.
	int len = StrLen(str);

	char* buffer = new char[len + 1]{};
	
	//for (int i = 0; i <= len; i++) buffer[i] = str[i];
	std::strcpy(buffer, str); //String Copy. buffer - получатель; str - строка источник.

	remove_symbol(buffer, ' ');
	to_lower(buffer);

	len = StrLen(buffer);
	for (int i = 0; i<=len/2; i++)
	{
		if (buffer[i] != buffer[len - i - 1])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}

//Исполнитель
/*
-----------------------------------------------------
|                                                   |
|   "Компьютерная академия ШАГ"                     |
|   Курс: БД011                                     |
|   Предмет: Основы програмvирования на языке C++   |
|                                                   |
|   Исполнитель: Курицын Алексей                    |
|   Преподаватель: Ковтун Олег                      |
|                                                   |
|   Екатеринбург - 2021                             |
|                                                   |
-----------------------------------------------------*/