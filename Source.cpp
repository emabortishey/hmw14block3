#include "Header.h"
#include "Priority_Queue.h"
#include "Queue.h"

void printer_queue(Priority_Queue& users, Queue& pages, Queue& time);

enum meow{PRINT = 1, ADD, EXTRACT};

int main()
{
	setlocale(LC_ALL, "Russian");
	string* buff = new string[5];
	// очередь с приоритетом для пользователей
	Priority_Queue users_prior(5);
	// очередь со временем уходящим на выполнение заказа
	Queue time(5);
	// очередь с количеством страниц заказа
	Queue pages(5);

	// заполнение буферного
	// массива пользоваталей для теста программы
	for (int i = 1; i <= 5; i++)
	{
		// тут при добавлении каунтера в стринг добавляется прикольный смайлик
		// и при каждом числе разный, потому что сначала я не учла что при присваивании
		// стрингу числа происходит преобразование типа, но я подумала
		// что это веселее чем простые цифры, поэтому оставила так
		buff[i-1] = i;
		buff[i-1].append(" user ");
	}

	// перенос значений из буфера в очередь пользователей
	users_prior.Add(buff[0], 3);
	users_prior.Add(buff[1], 5);
	users_prior.Add(buff[2], 1);
	users_prior.Add(buff[3], 4);
	users_prior.Add(buff[4], 2);

	// заполнение очереди страниц вручную
	pages.Add(34);
	pages.Add(12);
	pages.Add(22);
	pages.Add(9);
	pages.Add(14);

	// заполнение очереди времени вручную (скорость печати - 1 страница в 2 минуты)
	time.Add(pages[0] * 2);
	time.Add(pages[1] * 2);
	time.Add(pages[2] * 2);
	time.Add(pages[3] * 2);
	time.Add(pages[4] * 2);

	// вызов функции "приложения" для работы с очередью
	printer_queue(users_prior, pages, time);

	return 0;
}

void printer_queue(Priority_Queue& users, Queue& pages, Queue& time)
{
	// выбор меню
	int choice = -1;
	// буфер типа инт для ввода данных страниц и приоритета при добавлении в очередь
	int buff_int;
	// тот же буфер но в типе стринг для ввода имени пользователя при добавлении
	string buff_str;

	while (choice != 0)
	{
	cout << "Введите число в зависимости от своего выбора\n1.Вывести статистику\n2.Добавить в очередь пользователя\n3.Удалить пользователя из очереди ";
	cin >> choice;
	cout << "\n\n\n";
		switch (choice)
		{
		case PRINT:
		{
			for (int i = 0; i < users.GetLength(); i++)
			{
				// вывод с помощью перегрузки оператора квадратных скобочек
				cout << "Клиент номер " << i + 1 << ": " << users[i] << '\n';
				cout << "Количество страниц для распечатки: " << pages[i] << '\n';
				cout << "Затраты времени (страница/2 мин.): " << time[i] << "\n\n";
			}
			break;
		}
		case ADD:
		{
			cout << "\nДля добавления человека в очередь введите имя клиента: ";
			// помню что во 2 блоке (вроде) при выполнении проекта, еогда 
			// я пыталась использовать стринг вы сказали, что его нельзя брать истримом
			// и нужно использовать гетлайн, поэтому использую его для взятия значения
			// имени клиента
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
			break;
		}
		case EXTRACT:
		{
			// переменная содержащая индекст высшего приоритета в очереди
			// для корректного извлечение его из массива страниц и времени
			int prior_indx;
			cout << "ТЕКУЩИЙ ЗАКАЗ ПОДЛЕЖАЩИЙ ВЫПОЛНЕНИЮ: ";
			// сразу забираем самый приор. индекс перед экстрактом из юсеров
			prior_indx = users.max_prior_indx();
			// выводим имя клиента
			cout << "Клиент: " << users.Extract() << '\n';
			// с помощью отдельного метода вытаскиваем определённый элемент очереди 
			// из страниц и времени
			cout << "Количество страниц для распечатки: " << pages.ExtractWPrior(prior_indx) << '\n';
			cout << "Затраты времени (страница/2 мин.): " << time.ExtractWPrior(prior_indx) << "\n\n";
			break;
		}

		}
	}
}