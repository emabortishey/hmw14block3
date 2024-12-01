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
		prior[++QueueLength] = p;
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
	if (!IsEmpty())
	{
		return queue[QueueLength--];
	}
	else
	{
		return 0;
	}
}