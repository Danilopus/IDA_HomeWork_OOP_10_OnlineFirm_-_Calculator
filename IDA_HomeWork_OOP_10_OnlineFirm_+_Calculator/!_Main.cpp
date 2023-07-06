// HomeWork template project v 6.0 // 27.06.2023 //

/*

Перегрузка операторов

Задание 1
создать класса пользователь(клиент) для онлайн фирмы
который будет позволять узнавать количество текущих
клиентов в программе
комментарии:
клиент представлен именем, фамилией, адресом
и состоянием счёта.
в системе есть объекты в фоновой обработке(хранятся
гдето в векторе, листе, итп) и объекты в активной
работе(не в оснновной коллекции)
данные объекты должны влиять на количество клиентов
а временные объекты не должны вызывать такого эффекта

Задание 2
создать класс калькулятор который позволит выполнять
арифметические операции над числами
комментарии:
все данные в класс и его объекты приходят извне
в классе не хранится информации
операции требуются для бух-учёта
+ - * / %


*/

#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <conio.h>
//My own headers
#include "Service functions.h"
#include "MainMenu.h"

#include "ClientPerson.h"
#include "Calculator.h"



// Homework OOP 10 ----------------------------------------------------	


//Task 1 ClientPerson class demo with constant_client_counter
void Task_1(std::string name_of_task)
{	
	std::cout << std::endl << "Testing methods of class ClientPerson" << std::endl << std::endl;
	
	std::cout << "*** Constant clients";
	ClientPerson client_1("Petr", 111.33);
	client_1.ShowInfo();
	std::cout << std::endl << std::endl << "***\t***\t*** _CLIENT_COUNT -> " << ClientPerson::Get_CLIENT_COUNT() << std::endl;

	ClientPerson client_2("Andre", 777.55);
	client_2.ShowInfo();
	std::cout << std::endl << std::endl << "***\t***\t*** _CLIENT_COUNT -> " << ClientPerson::Get_CLIENT_COUNT() << std::endl;

	ClientPerson client_3("Daniel", 1005.100500);
	client_3.ShowInfo();
	std::cout << std::endl << std::endl << "***\t***\t*** _CLIENT_COUNT -> " << ClientPerson::Get_CLIENT_COUNT() << std::endl;

	std::cout << "\n\n*** temporary clients";	
	ClientPerson client_temp(client_3);
	client_temp.ShowInfo();
	std::cout << std::endl << std::endl << "***\t***\t*** _CLIENT_COUNT -> " << ClientPerson::Get_CLIENT_COUNT() << std::endl;

	
	_getch();
}

//Task 2 Calculator class demo
void Task_2(std::string name_of_task)
{
	/*
	 я провел исследования и обнаружил, что лучше всего справляются функции основанные только на double
	 все другие дополнительные перегрузки создают только проблему:
	 компилятору кажется что для работы с аргументом например int одинаково хорошо подойдут перегрузки и double и longlong
	 (при условии что отдельной перегрузки на int нету)
	 причем настолько хорошо, что он даже не знает что выбрать (хотя казалось бы longlong конечно!)
	 настолько не знает, что это приводит к проблеме компиляции!

	 Поэтому я принял решения сделать все функции только на double - самый жизнеспособный вариант

	 PS При наличии шаблона все явно не перегруженные типы используют шаблон - что short, что string. 
	 Поэтому от этого варианта отказался
	*/
	
	std::cout << std::endl << "Testing methods of class Calculator" << std::endl;
	//Argument testing with Summation ----------------------------------	
	//INTEGER
	std::cout << std::endl << "Calculator::Summation(111, 222) -> " << Calculator::Summation(111, 222);
	std::cout << std::endl << "Calculator::Summation(111LL, 222LL) -> " << Calculator::Summation(111LL, 222LL);
	std::cout << std::endl << "Calculator::Summation(111LL, size_t(222)) -> " << Calculator::Summation(111LL, size_t(222));
	std::cout << std::endl << std::endl << "Calculator::Summation(size_t(111), size_t(222)) -> " << Calculator::Summation(size_t(111), size_t(222));
	std::cout << std::endl << "Calculator::Summation(short(111), short(222)) -> " << Calculator::Summation(short(111), short(222));
	std::cout << std::endl << "Calculator::Summation('a', 'b') -> " << Calculator::Summation('a', 'b');

	//REAL
	std::cout << std::endl << std::endl << "Calculator::Summation(1.11, 2.22) -> " << Calculator::Summation(1.11, 2.22);
	std::cout << std::endl << "Calculator::Summation(1.11f, 2.22f) -> " << Calculator::Summation(1.11f, 2.22f);
	std::cout << std::endl << "Calculator::Summation(1.11, 2.22f) -> " << Calculator::Summation(1.11, 2.22f);

	//Other
	//E1067 std::cout << std::endl << Calculator::Summation("one", "two");
	ClientPerson client_1("Petr", 111.33);
	//E0413 std::cout << std::endl << Calculator::Summation(client_1, client_1);

	//Testing other methods --------------------------------------------
	std::cout << std::endl << std::endl << "Calculator::Substract(111LL, double(222)) -> " << Calculator::Substract(111LL, double(222));
	std::cout << std::endl << std::endl << "Calculator::Multiply(111LL, 2.22) -> " << Calculator::Multiply(111LL, 2.22);
	std::cout << std::endl << std::endl << "Calculator::Divide(char(222), 2.22f) -> " << Calculator::Divide(char(222), 2.22f);
	std::cout << std::endl << std::endl << "Calculator::Percentage(short(100), 15) -> " << Calculator::Percentage(short(100), 15) << "%";

	_getch();
}

//Task 3 
void Task_3() {}

//Task 4
void Task_4() {}

// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
	srand(time(NULL));
	//setlocale(LC_CTYPE, "Russian");
	//system("mode con cols=60 lines=40"); 
	Main_menu MainMenu;	
	MainMenu.AddElement("OOP Home Work 10: Static fields and methods");	// Homework name
	MainMenu.AddElement("Client of online firm class demo with static_client_counter");
	MainMenu.AddElement("Calculator class demo");

	do 
	{		
		MainMenu.Show_menu();
		if (!MainMenu.User_Choice_Handle(_getch()))	break;
	} while (true);
	return 0;
}

