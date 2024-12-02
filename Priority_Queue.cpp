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

void Priority_Queue::Print()
{
	for (int i = 0; i < QueueLength; i++)
	{
		cout << queue[i] << endl;
	}
}

string Priority_Queue::Extract()
{
	int prior_index = 0;
	string buff;
	if (!IsEmpty())
	{
		for (int i = 1; i < QueueLength; i++)
		{
			if (prior[prior_index] < prior[i])
			{
				prior_index = i;
				buff = queue[prior_index];
			}
		}

		QueueLength--;

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

string Priority_Queue::operator[](int indx)
{
	char buff[2]{ prior[indx] };
	string buff_str;
	stringstream buff_sstr;
	buff_sstr << prior[indx];
	buff_sstr >> buff_str;
	buff_str.append(" ");
	buff_str.append(queue[indx]);
	return buff_str;
}