#ifndef _ASSEMBLER_HPP
#define _ASSEMBLER_HPP

#include <vector>
#include <map>

std::map<std::string, int> assembler(std::vector<std::string> const& assembly);

enum CompareResult
{
	Equals = 1,
	Greater = 3,
	Lesser = 2,
	Empty = 0
};

#endif
