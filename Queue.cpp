#include "Queue.h"

Queue::Queue(int length) : QueueLength{ 0 }, MaxQueueLength{ length }, queue{ new string[length] } {}

void Queue::Clear()
{
	QueueLength = 0;
}

bool Queue::IsEmpty()
{
	return QueueLength == 0;
}

bool Queue::IsFull()
{
	return QueueLength == 40;
}

int Queue::GetLength()
{
	return QueueLength;
}

void Queue::Add(string s)
{
	if (!IsFull())
	{
		queue[++QueueLength] = s;
	}
}

void Queue::Print()
{
	for (int i = 0; i < QueueLength; i++)
	{
		cout << queue[i] << endl;
	}
}

string Queue::Extract()
{
	if (!IsEmpty())
	{
		return queue[QueueLength--];
	}
	else
	{
		return 0;
	}
}