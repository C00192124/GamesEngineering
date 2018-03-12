#pragma once
#include <mutex>
#include <iostream>
#include <condition_variable>

using namespace std;

struct Semaphore
{
public:
	Semaphore() {}
	Semaphore(int x) { count = x; }

	//wait method
	void P()
	{
		unique_lock<mutex> lock(myMutex);
		while (count <= 0)
		{
			cout << "waiting..." << endl;
			conVar.wait(lock);
		}
		count -= 1;
	}

	//increment method
	void V()
	{
		unique_lock<mutex> lock(myMutex);
		count += 1;
		conVar.notify_one();
	}

private:
	int count;
	mutex myMutex;
	condition_variable conVar;
};