#pragma once

// program 3.10~12:

#include <iostream>
#include <memory>

using namespace std;

template <class T>
class Queue
{
public:
	Queue(int queueCapacity = 10);
	bool IsEmpty();
	T& Front();
	T& Rear();
	void Push(T const & x);
	void Pop();
private:
	T * queue;
	int front;
	int rear;
	int capacity;
};

template <class T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity)
{
	queue = new T[capacity];
	front = rear = -1;
}

template <class T>
inline bool  Queue<T>::IsEmpty() { return front == rear; }

template <class T>
inline T& Queue<T>::Front()
{
	if (IsEmpty()) throw "Queue is empty. No front element";
	return queue[(front + 1) % capacity];
}

template <class T>
inline T& Queue<T>::Rear()
{
	if (IsEmpty()) throw "Queue is empty. No rear element";
	return queue[rear];
}

// doubling queue capacity
template <class T>
void Queue<T>::Push(T const & x)
{
	if ((rear+1) % capacity == front || (front == -1 && rear == capacity-1))
	{
		T* newQueue = new T[2 * capacity];
		// allocate an array with twice the capacity
		int start = (front + 1) % capacity;
		int index = 0;
		int size = abs(start - rear) + 1;
		while (size > 0) {
			newQueue[index++] = queue[start];
			start = (start + 1) % capacity;
			size--;
		}
		// switch to new Queue
		front = -1;
		rear = index - 1;
		capacity *= 2;
		delete[] queue;
		queue = newQueue;
	}

	rear = (rear + 1) % capacity;
	queue[rear] = x;
}

template <class T>
void Queue<T>::Pop()
{
	if (IsEmpty()) throw "Queue is empty. Cannot delelte.";
	front = (front + 1) % capacity;
	queue[front].~T();
}
