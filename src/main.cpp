#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

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
  string file;
  while(true)
  {
    cout << "\033[2J\033[1;1H";
    cout << "Path to file: ";
    getline(cin, file);
    if(file == " ") break;
    ifstream fin(file);
    if(!fin)
    {
      cout << "Not found file " << file << endl;
    }
    else
    {
      vector<string> ins;
      string tmp;
      while(getline(fin, tmp))
      {
        ins.push_back(tmp);
      }
      print_result(ins);
    }
    char s = getchar();
    if(s == '1') break;
  }

  return 0;
}
