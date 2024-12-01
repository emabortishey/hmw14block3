#include "Header.h"
#include "Priority_Queue.h"
#include "Queue.h"

enum meow{PRINT = 1, ADD, EXTRACT};

int main()
{
	string* buff = new string[5];
	Priority_Queue users_prior(5);
	Queue time(5);
	Queue pages(5);

	for (int i = 1; i <= 5; i++)
	{
		buff[i-1] = i;
		buff[i-1].append(" user ");
		cout << buff[i - 1];
	}

	users_prior.Add(buff[0], 3);
	users_prior.Add(buff[1], 5);
	users_prior.Add(buff[2], 1);
	users_prior.Add(buff[3], 4);
	users_prior.Add(buff[4], 2);

	pages.Add(34);
	pages.Add(12);
	pages.Add(22);
	pages.Add(9);
	pages.Add(14);

	time.Add(pages[0] * 2);
	time.Add(pages[1] * 2);
	time.Add(pages[2] * 2);
	time.Add(pages[3] * 2);
	time.Add(pages[4] * 2);

	time.Print();

	cout << users_prior.Extract();

	return 0;
}

void printer_queue(Priority_Queue& obj1, Queue& obj2)
{
	int choice = 0;
	switch (choice)
	{
		cout << "Введите число в зависимости от своего выбора\n1.Вывести статистику\n2.Добавить в очередь пользователя\n3.Удалить пользователя из очереди\t";
		cin >> choice;
	case PRINT:
	{

	}
	case ADD:
	{

	}
	case EXTRACT:
	{

	}
	}
}