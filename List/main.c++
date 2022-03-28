#include <iostream>
#include <clocale>
#include "list.c++"

using namespace std;

template<typename T>
void printMenu(List<T>& l1, List<T>& l2);

template<typename T>
void createList(List<T>& l);

template<typename T>
void printList(List<T>& listToPrint);

template<typename T>
List<T>& combineLists(List<T>& l1, List<T>& l2);

template<typename T>
void deleteEvenCells(List<T>& l);

template<typename T>
void magicalRework(List<T>& l);


int main() {
	setlocale(LC_ALL, "ru");

	// Главные переменные
	List<int> L1;
	List<int> L2;
	List<int> L;

	//Переменные для пользовательского ввода.
	int userMenuChoice = -1;
	int userCreatingChoice = -1;

	// Главный меню-цикл.
	while (userMenuChoice != 0) { 
		system("cls");
		printMenu(L1, L2);

		cin >> userMenuChoice;
		cin.ignore();

		switch (userMenuChoice) {

		//формирование L1 и L2
		case 1:
			cout << "Какой список вы хотите заполнить?\n";
			cout << "Ваш выбор: ";
			cin >> userCreatingChoice;
			switch (userCreatingChoice)
			{
			case 1:
				createList(L1);
				break;
			case 2:
				createList(L2);
				break;
			default:
				cout << "Недопустимый ввод!\n";
				cin.clear();
				system("pause");
				break;
			}
			system("pause");
			break;

		//формирование L
		case 2:
			if (L1.getSize() && L2.getSize())
			{
				cout << "Список L - set L1 и L2: ";
				printList(combineLists(L1, L2));
				cout << endl;
			}
			else
			{
				cout << "Действие невозможно! Заполните все списки.\n";
			}
			system("pause");
			break;

		//Удалить четные ячейки из L1
		case 3:
			if (L1.getSize())
			{
				deleteEvenCells(L1);
				cout << "Ячейки на чётных позициях удалены из списка L1\n";
			}
			else
			{
				cout << "Действие невозможно! Сформируйте список L1\n";
			}
			system("pause");
			break;
			
		//Вставка после пар ячеек их суммы в L2
		case 4:
			if (L2.getSize())
			{
				magicalRework(L2);
				cout << "В список L2 после каждой пары ячеек была вставлена их сумма.\n";
			}
			else
			{
				cout << "Действие невозможно! Сформируйте список L2\n";
			}
			system("pause");
			break;
			
		case 0:
			cout << "До свидания!\n";
			userMenuChoice = 0;
			system("pause");
			break;

		default:
			cout << "Я не понимаю вас, повторите ввод\n";
			cin.clear();
			system("pause");
			break;

		}
	}
		return 0;
}


//Функция вывода меню
template<typename T>
void printMenu(List<T>& l1, List<T>& l2)
{
	cout << "Практическая работа #5 ИКБО-03-21 Мазанов А.Е. Вариант 1\n\n"
		"Задание 5 - Однонаправленный список.\n"
		"~~~~~~~~~~~~~~~~~Меню~~~~~~~~~~~~~~~\n"
		"Списки:" << endl << "L1: ";
	printList(l1);
	cout << endl << "L2: ";
	printList(l2);
	cout << endl;
	cout << "Введите [1], чтобы сформировать списки.\n"
		"Введите [2], чтобы сформировать и вывести список L - \"set\" L1 и L2.\n"
		"Введите [3], чтобы удалить из L1 узлы с чётными позициями.\n"
		"Введите [4], чтобы вставить в L2 после каждой пары узлов новый узел - сумму предшествующей пары.\n"
		"Введите [0], чтобы закончить работу программы.\n";
	cout << "Ваш выбор: ";
}


//Функция задания списка
template<typename T>
void createList(List<T>& l)
{
	size_t size;
	T currentVal;
	cout << "Введите количество вводимых ячеек: ";
	cin >> size;
	cout << "Введите " << size << " значений: ";
	for (size_t i = 0; i < size; i++)
	{
		cin >> currentVal;
		l.pushBack(currentVal);
	}
}


//Функция вывода списка
template<typename T>
void printList(List<T>& listToPrint)
{	
	if (listToPrint.getSize())
	{
		size_t printSize = listToPrint.getSize();
		for (size_t i = 0; i < printSize; i++)
		{
			cout << listToPrint[i] << " ";
		}
	}
	else
	{
		cout << "Пуст";
	}
}


//Функция сборки так называемого set'a из L1 и L2
template<typename T>
List<T>& combineLists(List<T>& l1, List<T>& l2)
{
	List<T>* result = new List<T>;
	T tempVal;
	for (size_t i = 0; i < l1.getSize(); i++)
	{
		tempVal = l1[i];
		if (result->lFind(tempVal) == -1)
		{
			result->pushBack(tempVal);
		}
	}
	for (size_t i = 0; i < l2.getSize(); i++)
	{
		tempVal = l2[i];
		if (result->lFind(tempVal) == -1)
		{
			result->pushBack(tempVal);
		}
	}
	return *result;
}


//Удаление ячеек на четных позициях
template<typename T>
void deleteEvenCells(List<T>& l)
{
	/* Практическим путём было выяснено, что если последовательно удалять из массива
	* ячейки с индексами i = 0, 1, ... n, где n - кол-во ячеек с четным номером,
	* то будут удалены все ячейки на четных позициях, т.к при удалении какой-либо ячейки 
	* инексация свдигается. А кол-во четных позиций будет равно размеру массива,
	* целочисленно подёленному на 2. */
	size_t forSize = l.getSize() / 2;
	for (size_t i = 0; i < forSize; i++)
	{
		l.earase(i);
	}
}


//Функция для вставки суммы пары после пары ячеек 
template<typename T>
void magicalRework(List<T>& l)
{
	T currentSum = 0;
	short pairCounter = 0;
	for (size_t i = 0; i < l.getSize(); i++)
	{
		pairCounter++;
		currentSum += l[i];
		if (pairCounter == 2)
		{
			l.insert(currentSum, ++i);
			currentSum = 0;
			pairCounter = 0;

		}
	}
}