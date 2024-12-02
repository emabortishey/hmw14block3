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
	cout << "������� ����� � ����������� �� ������ ������\n1.������� ����������\n2.�������� � ������� ������������\n3.������� ������������ �� �������\t";
	cin >> choice;
	switch (choice)
	{
	case PRINT:
	{
		for (int i = 0; i < users.GetLength(); i++)
		{
			cout << "������ ����� " << i+1 << ": " << users[i] << '\n';
			cout << "���������� ������� ��� ����������: " << pages[i] << '\n';
			cout << "������� ������� (��������/2 ���.): " << time[i] << "\n\n";
		}
	}
	case ADD:
	{
		cout << "\n��� ���������� �������� � ������� ������� ��� �������: ";
		getline(cin, buff_str);
		cout << "\n������� ��������� ���������� ������: ";
		cin >> buff_int;
		users.Add(buff_str, buff_int);
		cout << "\n������� ���������� ������� ��� ����������: ";
		cin >> buff_int;
		pages.Add(buff_int);
		cout << "\n���������� ����� " << buff_int * 2 << " �����";
		time.Add(buff_int * 2);
		cout << "������ ������� ��������!! :D";
	}
	case EXTRACT:
	{
		int prior_indx;
		cout << "������� ����� ���������� ����������: ";
		prior_indx = users.max_prior_indx();
		cout << "������: " << users.Extract() << '\n';
		cout << "���������� ������� ��� ����������: " << pages.ExtractWPrior(prior_indx) << '\n';
		cout << "������� ������� (��������/2 ���.): " << time.ExtractWPrior(prior_indx) << "\n\n";
	}

	cout << "������� ����� � ����������� �� ������ ������\n1.������� ����������\n2.�������� � ������� ������������\n3.������� ������������ �� �������\t";
	cin >> choice;
	}
}