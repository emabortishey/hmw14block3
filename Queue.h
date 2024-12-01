#pragma once
#include "Header.h"

class Queue
{
	int QueueLength;
	int MaxQueueLength;
	int* queue;
public:
	Queue(int length);
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int GetLength();
	void Add(int s);
	void Print();
	int Extract();
	int operator[](int indx);
};

