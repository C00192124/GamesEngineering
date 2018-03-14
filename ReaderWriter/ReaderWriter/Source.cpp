#pragma once
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

struct Semaphore
{
	int mutexReader = 1, mutexDB = 1;
};

void Reader();
void Writer();

void P(int &x);
void V(int &x);

Semaphore semaphore;

int readerCount = 0;

void main()
{
	thread tReader(Reader);
	thread tWriter(Writer);

	tReader.join();
	tWriter.join();
}

//Try
void P(int &x)
{
	while (x <= 0)
	{
		cout << "waiting..." << endl;
	}
	x -= 1;
}

//Increment
void V(int &x)
{
	x += 1;
}

void Reader()
{
	bool running = true;
	while (running)
	{
		cout << this_thread::get_id() << endl;
		this_thread::sleep_for(chrono::seconds(1));
		P(semaphore.mutexReader);
		readerCount += 1;
		if (readerCount == 1)
		{
			P(semaphore.mutexDB);
		}
		V(semaphore.mutexReader);
		
		cout << "Reading..." << endl;
		
		P(semaphore.mutexReader);
		readerCount -= 1;
		if (readerCount == 0)
		{
			V(semaphore.mutexDB);
		}
		V(semaphore.mutexReader);
	}
}
void Writer()
{
	bool running = true;
	while (running)
	{
		cout << this_thread::get_id() << endl;
		this_thread::sleep_for(chrono::seconds(1));
		P(semaphore.mutexDB);
		
		cout << "Writing..." << endl;

		V(semaphore.mutexDB);
	}
}