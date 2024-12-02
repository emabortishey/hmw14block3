#include "Header.h"
#include "Priority_Queue.h"
#include "Queue.h"

void printer_queue(Priority_Queue& users, Queue& pages, Queue& time);

enum meow{PRINT = 1, ADD, EXTRACT};

int main()
{
	setlocale(LC_ALL, "Russian");
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

	printer_queue(users_prior, pages, time);

	return 0;
}

void printer_queue(Priority_Queue& users, Queue& pages, Queue& time)
{
	int choice = 0;
	int buff_int;
	string buff_str;
	cout << "Введите число в зависимости от своего выбора\n1.Вывести статистику\n2.Добавить в очередь пользователя\n3.Удалить пользователя из очереди\t";
	cin >> choice;
	switch (choice)
	{
	case PRINT:
	{
		for (int i = 0; i < users.GetLength(); i++)
		{
			cout << "Клиент номер " << i+1 << ": " << users[i] << '\n';
			cout << "Количество страниц для распечатки: " << pages[i] << '\n';
			cout << "Затраты времени (страница/2 мин.): " << time[i] << "\n\n";
		}
	}
	case ADD:
	{
		cout << "\nДля добавления человека в очередь введите имя клиента: ";
		getline(cin, buff_str);
		cout << "\nВведите приоритет исполнения заказа: ";
		cin >> buff_int;
		users.Add(buff_str, buff_int);
		cout << "\nВведите количество страниц для распечатки: ";
		cin >> buff_int;
		pages.Add(buff_int);
		cout << "\nРаспечатка займёт " << buff_int * 2 << " минут";
		time.Add(buff_int * 2);
		cout << "Клиент успешно добавлен!! :D";
	}
	case EXTRACT:
	{
		int prior_indx;
		cout << "ТЕКУЩИЙ ЗАКАЗ ПОДЛЕЖАЩИЙ ВЫПОЛНЕНИЮ: ";
		prior_indx = users.max_prior_indx();
		cout << "Клиент: " << users.Extract() << '\n';
		cout << "Количество страниц для распечатки: " << pages.ExtractWPrior(prior_indx) << '\n';
		cout << "Затраты времени (страница/2 мин.): " << time.ExtractWPrior(prior_indx) << "\n\n";
	}

	cout << "Введите число в зависимости от своего выбора\n1.Вывести статистику\n2.Добавить в очередь пользователя\n3.Удалить пользователя из очереди\t";
	cin >> choice;
	}
}