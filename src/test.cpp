#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "assembler.hpp"
#include "tests.hpp"

using namespace std;

// map<string, int> programme = assembler(instructions);

bool Compare(map<string, int> _first, map<string, int> _second)
{
	bool is = true;
	auto a = _first.begin();
	auto b = _second.begin();
	while(a != _first.end() || b != _second.end())
	{
		if(a->first != b->first)
		{
			is = false;
			break;
		}
		else if(a->second != b->second)
		{
			is = false;
			break;
		}
		a++; b++;
	}
	return is;
}

int main()
{
	int c = 1;
	for(auto i = tests.begin(); i != tests.end(); i++)
	{
		if(Compare(assembler(i->first), i->second)) cout << "Test " << c << " Passed" << endl;
		else cout << "Test " << c << " Failed" << endl;
		c++;
	}


	return 0;
}