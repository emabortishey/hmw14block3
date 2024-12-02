#include "Priority_Queue.h"
Priority_Queue::Priority_Queue(int length) : QueueLength{ 0 }, MaxQueueLength{ length }, queue{ new string[length] }, prior { new int[length] } {}

void Priority_Queue::Clear()
{
	QueueLength = 0;
}

bool Priority_Queue::IsEmpty()
{
	return QueueLength == 0;
}

bool Priority_Queue::IsFull()
{
	return QueueLength == 40;
}

int Priority_Queue::GetLength()
{
	return QueueLength;
}

void Priority_Queue::Add(string s, int p)
{
	if (!IsFull())
	{
		queue[QueueLength] = s;
		prior[QueueLength++] = p;
	}
}

// вывод всей очереди сразу, я решила не париться над
// выводом в соответствии с приоритетами, мне лень
void Priority_Queue::Print()
{
	for (int i = 0; i < QueueLength; i++)
	{
		cout << queue[i] << endl;
	}
}

// думаю тут подробное обьяснение не требуется
string Priority_Queue::Extract()
{
	int prior_index = 0;
	string buff;
	if (!IsEmpty())
	{
		// ищем нужный индекс и строку
		for (int i = 1; i < QueueLength; i++)
		{
			if (prior[prior_index] < prior[i])
			{
				prior_index = i;
				buff = queue[prior_index];
			}
		}

		// умеьшаем текущую длину
		QueueLength--;
		// сдвигаем очередь
		for (int i = prior_index; i < QueueLength; i++)
		{
			queue[i] = queue[i + 1];
			prior[i] = prior[i + 1];
		}

		return buff;
	}
	else
	{
		return 0;
	}
}

int Priority_Queue::max_prior_indx()
{
	// то же самое что и в эекстракт, но тут возвращается индекс макс.
	// приоритета, и не происходит смещения
	int max_prior_index = 0;
	for (int i = 1; i < QueueLength; i++)
	{
		if (prior[max_prior_index] < prior[i])
		{
			max_prior_index = i;
		}
	}
	return max_prior_index;
}

// перегрузка квадратных скобок именно в этом задании
// для меня должна была выводить приоритет + имя клиента
// поэтому я заглянула в интернет и нашла библиотеку
// сстринг, как я поняла она с помощью перегрузок
// операторов стрелочек может как приниматьт
// значения так и передавать в другие переменные и я решила 
// использовать её для того, чтобы корректно записать числа
// в переменную стринг, без преобразований в смайлики и
// прочего бреда
string Priority_Queue::operator[](int indx)
{
	string buff_str;
	stringstream buff_sstr;
	buff_sstr << prior[indx];
	buff_sstr >> buff_str;
	buff_str.append(" | ");
	buff_str.append(queue[indx]);
	return buff_str;
}