#include<iostream>
#include<ctype.h> //Для проверки является ли символ цифрой
#include<Windows.h>
//using namespace std;

//TODO: 2021_03_10
/*
В проект CStrings добавить функции :
bool is_ip_address(char str[]);	//Проверяет, является ли строка IP-адресом --done
bool is_mac_address(char str[]);//Проверяет, является ли строка MAC-адресом --todo
*/

//#define CW_CSTRINGS_FIRST_MEET //Первое знакомство со строками
//#define HW_CSTRINGS_2021_02_24 //Первое знакомство со строками

int StrLen(char str[]);			//Вычисляет длинну строки

void to_upper(char str[]);		//переводит строку в верхний регистр;
void to_lower(char str[]);		//переводит строку в нижний регистр;
void capitalize(char str[]);	//первую букву каждого слова в предложении делает заглвыной;
void shrink(char str[]);		//удаляет лишние пробелы из предложения;
void remove_symbol(char str[], char symbol); //Удаляет все вхождения символа

bool is_palindrome(char str[]);	//Определяет, является ли строка палиндромом.
bool is_int_number(char str[]);	//Определяет, является ли строка целым числом.
bool is_bin_number(char str[]);	//Определяет, является ли строка Двоичным числом.
bool is_hex_number(char str[]);	//Определяет, является ли строка Шестнадцатеричным числом.

bool is_ip_address(char str[]);	//Проверяет, является ли строка IP-адресом
bool is_mac_address(char str[]);//Проверяет, является ли строка MAC-адресом

int  to_int_number(char str[]);	//Если строка - целое число, то функция возвращает его значение.
int  bin_to_dec(char str[]);	//Если строка - Двоичное число, то функция возвращает его десятичное значение.
int  hex_to_dec(char str[]);	//Если строка - Шестнадцатеричное число, то функция возвращает его десятичное значение.

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
	char str[] = "123 321";
	//char str[] = "1234321";
	//char str[] = "123456";
	//char str[] = "Аргентина манит негра";
 	
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
	std::cout << (is_int_number(str)?"Строка число!":"Строка не число!") << std::endl;

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

	const int n = 256;
	char str[n]{};

	std::cout << "String is IPv4?" << std::endl;
	std::cout << "Введите строку: ";
	std::cin.getline(str, n);

	//std::cout << (is_int_number(str) ? "Число" : "Не число") << std::endl;
	//std::cout << (is_bin_number(str) ? "Двоичное" : "Не двоичное") << std::endl;
	//std::cout << (is_hex_number(str) ? "HEX" : "NOT HEX") << std::endl;
	std::cout << (is_ip_address(str) ? "it's IPv4" : "it's NOT IPv4") << std::endl;
	//std::cout << str <<"(bin) = "<< bin_to_dec(str) << "(dec)" << std::endl;
	//std::cout << str <<"(bin) = "<< bin_to_dec(str) << "(dec)" << std::endl;
	//std::cout << str <<"(HEX) = "<< hex_to_dec(str) << "(dec)" << std::endl;


	//std::cout << (is_int_number(str) ? to_int_number(str) : 0) * 2 << std::endl;

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

bool is_int_number(char str[])
{//Определяет, является ли строка целым числом.

	//int len = StrLen(str);
	//char* buffer = new char[len + 1]{};
	//std::strcpy(buffer, str);

	//remove_symbol(buffer, ' ');

	//for (int i = 0; buffer[i]; i++)
	//{
	//	if (buffer[i] < '0' || buffer[i]>'9')
	//	{	
	//		delete[] buffer;
	//		return false;
	//	}
	//}
	//delete[] buffer;

	if (!str[0]) return false; //!!!

	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ') return false;
		if (str[i] == ' ' && str[i + 1] == ' ') return false;
	}

	return true;
}

bool is_bin_number(char str[])
{//Определяет, является ли строка Двоичным числом.
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ') return false;
		if (str[i - 1] == ' ' && str[i] == ' ' && str[i + 1] == ' ') return false;
	}

	return true;
}

bool is_hex_number(char str[])
{//Определяет, является ли строка Шестнадцатеричным числом.
	
	for (int i = str[0]=='0' && str[1] =='x' ? 2:0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9') &&
			!(str[i] >= 'A' && str[i] <= 'F') &&
			!(str[i] >= 'a' && str[i] <= 'f') &&
			str[i] != ' ') return false;
		if (str[i] == ' ' && str[i + 1] == ' ') return false;
	}
	return true;
}

bool is_ip_address(char str[])
{//Проверяет, является ли строка IP-адресом
//0.0.0.0 - 255.255.255.255

	bool is_ip = true;

	int len_group = 4;
	char* one_group = new char[len_group] {};
	char* two_group = new char[len_group] {};
	char* three_group = new char[len_group] {};
	char* four_group = new char[len_group] {};

	int point_counter = 0;
	int digit_counter = 0;

	if (str[0] == '.')
	{//вначале строки не может стоять точка
		is_ip = false;
	}

	for (int i = 0; str[i]; i++)
	{
		if (!is_ip) break; //Выход из цикла по какой-нибудь ошибке...

		if (str[i] != '.' && !(str[i]>= '0' && str[i] <= '9')) //Встреча недопустимого символа
		{
			is_ip = false;
			break;
		}

		if (str[i] == '.') //Переход по группам
		{
			if (++point_counter > 3) //В строке больше трёх точек
			{
				is_ip = false;
				break;
			}
			digit_counter = 0;

			continue;
		}

		if (digit_counter > 2) //В группе больше трех символов
		{
			is_ip = false;
			break;
		}

		switch (point_counter)
		{
		case 0:
			one_group[digit_counter++] = str[i];
			break;
		case 1:
			two_group[digit_counter++] = str[i];
			break;
		case 2:
			three_group[digit_counter++] = str[i];
			break;
		case 3:
			four_group[digit_counter++] = str[i];
			break;
		default:
			break;
		}

	}
	
	if (is_ip && point_counter == 3 &&
		is_int_number(one_group) && is_int_number(two_group) && is_int_number(three_group) && is_int_number(four_group))
	{
		if ((to_int_number(one_group) >= 0 && to_int_number(one_group) <= 255) &&
			(to_int_number(two_group) >= 0 && to_int_number(two_group) <= 255) &&
			(to_int_number(three_group) >= 0 && to_int_number(three_group) <= 255) &&
			(to_int_number(four_group) >= 0 && to_int_number(four_group) <= 255))
		{//от 0 - 255
			is_ip = true;
		}
		else
		{
			is_ip = false;
		}

	}
	else
	{//Одна из групп не является целым числом.
		is_ip = false;
	}

	//Удалить временные динамические массивы:
	delete[] one_group;
	delete[] two_group;
	delete[] three_group;
	delete[] four_group;

	return is_ip;
}

bool is_mac_address(char str[])
{//Проверяет, является ли строка MAC-адресом
//00 00 00 00 00 00 - ff ff ff ff ff ff
//00:00:00:00:00:00 - ff:ff:ff:ff:ff:ff
//00-00-00-00-00-00 - ff-ff-ff-ff-ff-ff
//000000000000 - ffffffffffff



	return false;
}

int to_int_number(char str[])
{//Если строка - целое число, то функция возвращает его значение.
	if (!is_int_number(str))return 0;

	int number = 0;

	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ') continue;
		number *= 10;
		number += str[i] - 48;
	}

	return number;
}

int bin_to_dec(char str[])
{//Если строка - Двоичное число, то функция возвращает его десятичное значение.

	if (!is_bin_number(str)) return 0;

	int n = StrLen(str); //Разрядность числа.
	int decimal = 0; //Конечное десятичное число
	int weight = 1; //Весовой коэффициент разряда.

	for (int i = n - 1; i>=0 ; i--)
	{
		if (str[i] != ' ')
		{
			decimal += (str[i] - 48) * weight;
			weight *= 2;
		}
	}
	return decimal;
}

int hex_to_dec(char str[])
{//Если строка - Шестнадцатеричное число, то функция возвращает его десятичное значение.
	
	if (!is_hex_number(str)) return 0;

	int n = StrLen(str);//Значение разряда. Разрядность числа.
	char* buffer = new char[n + 1]{};
	strcpy(buffer, str);
	to_upper(buffer);

	int decimal = 0; //Конечное десятичное число
	int weight = 1;//Весовой коэфициент
	
	for (int i = n - 1; i >= 0; i--)
	{
		if (buffer[i] == 'X') break;
		if (buffer[i] != ' ')
		{
			decimal += (buffer[i] - (isdigit(buffer[i]) ? 48 : 55)) * weight;
			weight *= 16;
		}
	}
	return decimal;
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