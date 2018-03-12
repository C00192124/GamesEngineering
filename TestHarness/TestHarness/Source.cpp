#include <iostream>
#include <stdio.h>
#include <assert.h>
using namespace std;

class Method
{
public:
	int method(int x, int y) {
		if (x > y)
			max = x;
		else
			max = x;
		return max;
	}

private:
	int max;
};

void printNumber(int *i);

void main()
{
	Method m;
	int i = m.method(1, 2);
	printNumber(&i);
	system("PAUSE");
}

void printNumber(int *i)
{
	assert(i != NULL);
	printf("%d\n", *i);
}