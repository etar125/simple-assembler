#include <map>
#include <string>
#include <vector>
#include <iostream>

#include "assembler.hpp"
using namespace std;

void print_result(vector<string> instructions)
{
  map<string, int> programme = assembler(instructions);

  for (auto i = programme.begin(); i != programme.end(); ++i)
  {
    cout << i->first << ": " << i->second << endl;
  }
  cout << endl;
}

int main(void)
{
  // Jump if not equals
  print_result(
  {
    "mov c 0",
    "mov a 2",
    "mov b 0",
    "begin:",
    "inc c",
    "inc b",
    "cmp a b",
    "jne begin",
    "inc b",
    "inc a"
  });

  return 0;
}
