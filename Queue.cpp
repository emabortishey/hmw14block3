#include "Queue.h"

Queue::Queue(int length) : QueueLength{ 0 }, MaxQueueLength{ length }, queue{ new int[length] } {}

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

void Queue::Add(int s)
{
	if (!IsFull())
	{
		queue[QueueLength++] = s;
	}
}

void Queue::Print()
{
	for (int i = 0; i < QueueLength; i++)
	{
		cout << queue[i] << endl;
	}
}

int Queue::Extract()
{
	if (!IsEmpty())
	{
		return queue[--QueueLength];
	}
	else
	{
		return 0;
	}
}

int Queue::ExtractWPrior(int prior)
{
	if (!IsEmpty())
	{
		return queue[prior];

		for (int i = prior; i < QueueLength; i++)
		{
			queue[i] = queue[i + 1];
		}
	}
	else
	{
		return 0;
	}
}

int Queue::operator[](int indx)
{
	return queue[indx];
}