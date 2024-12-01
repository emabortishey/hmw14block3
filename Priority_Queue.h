#pragma once
#include "Header.h"

class Priority_Queue
{
	int QueueLength;
	int MaxQueueLength;
	string* queue;
	int* prior;
public:
	Priority_Queue(int length);
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int GetLength();
	void Add(string s, int p);
	void Print();
	string Extract();
};

