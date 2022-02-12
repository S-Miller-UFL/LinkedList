#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "leaker.h"
using namespace std;

int main()
{
	LinkedList<int> access;
	
	for (int i = 0; i < 10; i++)
	{
		access.AddHead(i);
		access.AddTail(i);
	}
}