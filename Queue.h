#pragma once
#include "Header.h"

class Queue
{
	int QueueLength;
	int MaxQueueLength;
	string* queue;
public:
	Queue(int length);
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int GetLength();
	void Add(string s);
	void Print();
	string Extract();
};

