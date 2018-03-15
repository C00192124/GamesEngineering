#pragma once
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

struct Semaphore
{
public:
	//Try
	void P()
	{
		while (m_lock <= 0)
		{
			cout << "waiting..." << endl;
		}
		m_lock -= 1;
	}

	//Increment
	void V()
	{
		m_lock += 1;
	}

private:
	int m_lock = 1;
};

void Reader();
void Writer();

//lock for reader
Semaphore readerSem;
//lock for db
Semaphore dbSem;

int readerCount = 0;

void main()
{
	thread tReader(Reader);
	thread tWriter(Writer);

	tReader.join();
	tWriter.join();
}

void Reader()
{
	bool running = true;
	while (running)
	{
		cout << this_thread::get_id() << endl;
		this_thread::sleep_for(chrono::seconds(1));
		readerSem.P();
		readerCount += 1;
		if (readerCount == 1)
		{
			dbSem.P();
		}
		readerSem.V();
		
		cout << "Reading..." << endl;
		
		readerSem.P();
		readerCount -= 1;
		if (readerCount == 0)
		{
			dbSem.V();
		}
		readerSem.V();
	}
}
void Writer()
{
	bool running = true;
	while (running)
	{
		cout << this_thread::get_id() << endl;
		this_thread::sleep_for(chrono::seconds(1));
		dbSem.P();
		
		cout << "Writing..." << endl;

		dbSem.V();
	}
}