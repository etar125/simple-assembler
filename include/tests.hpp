#include <string>
#include <vector>
#include <map>

using namespace std;

map<vector<string>, map<string, int>> tests
{
	// test 1 (math)

	{
		{
			"mov a 2",
			"mov b 2",
			"add a b",
			"mov c a",
			"mul a a",
			"sub a b",
			"div a b",
			"mov c a", // 7
			"inc a", // 8
			"dec b" // 1
		},

		{
			{ "a", 8 },
			{ "b", 1 },
			{ "c", 7 }
		}
	}
};