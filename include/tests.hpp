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
	},

	// calculating 2^15

	{
		{
			"mov a 2",
			"mov b 2",
			"mov c 0",
			"loop:",
			"mul a b",
			"inc c",
			"cmp c 14",
			"jl loop",
			"mov b 3"
		},

		{
			{ "a", 32768 },
			{ "b", 3 },
			{ "c", 14 }
		}
	}
};