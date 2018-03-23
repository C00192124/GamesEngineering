#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <mutex>
#include <condition_variable>

using namespace std;

struct Semaphore
{
public:
	int m_lock = 1;
	mutex m_mutex;
	condition_variable m_con;
};

void Reader();
void Writer();

void P(Semaphore &s);
void V(Semaphore &s);

//lock for reader
Semaphore readerSem;
//lock for db
Semaphore dbSem;

int readerCount = 0;

void main()
{
	thread tReader(Reader);
	thread tWriter(Writer);

	thread tReader2(Reader);
	thread tWriter2(Writer);

	tReader.join();
	tWriter.join();

	tReader2.join();
	tWriter2.join();

}

void Reader()
{
	bool running = true;
	while (running)
	{
		P(readerSem);
		readerCount += 1;
		if (readerCount == 1)
		{
			cout << "reading..." << endl;
			P(dbSem);
		}
		V(readerSem);
		
		P(readerSem);
		readerCount -= 1;
		if (readerCount == 0)
		{
			cout << "reader finished" << endl;
			V(dbSem);
		}
		V(readerSem);

		this_thread::sleep_for(chrono::seconds(1));
	}
}
void Writer()
{
	bool running = true;
	while (running)
	{
		
		P(dbSem);
		
		cout << "writing..." << endl;
		cout << "writer finished" << endl;

		V(dbSem);

		this_thread::sleep_for(chrono::seconds(1));
	}
}

//Try
void P(Semaphore &s)
{
	unique_lock<mutex> lock(s.m_mutex);
	while (s.m_lock <= 0)
	{
		s.m_con.wait(lock);
	}
	s.m_lock -= 1;
}

//Increment
void V(Semaphore &s)
{
	unique_lock<mutex> lock(s.m_mutex);
	s.m_lock += 1;
	s.m_con.notify_one();
}