#include <map>
#include <cctype>
#include <vector>
#include <string>
#include <sstream>

#include "assembler.hpp"

static std::vector<std::string> split(std::string const& str)
{
  std::string token;
  std::vector<std::string> result;
  std::istringstream iss(str, std::istringstream::in);

  while (iss >> token) result.push_back(token);

  return result;
}

std::map<std::string, int> assembler(std::vector<std::string> const& assembly)
{
  std::map<std::string, int> registers;
  CompareResult cr = CompareResult::Empty;
  std::map<std::string, int> labels;

  auto get_val = [&](std::string ins) -> int
  {
    return isalpha(ins[0]) ? registers[ins] : std::stoi(ins);
  };
  std::vector<int> lastcall;
  int countcalli = 0;

  for (int i = 0; i < assembly.size(); i++)
  {
    std::vector<std::string> instruction = split(assembly[i]);
    if (instruction[0][instruction[0].length()-1] == ':') labels.insert({ instruction[0].substr(0, instruction[0].length()-1), i });
  }

  for (int i = 0; i < assembly.size(); i++)
  {
    std::vector<std::string> instruction = split(assembly[i]);

    if (instruction[0][0] == ';') continue;
    else if (instruction[0] == "nop") continue;
    else if (instruction[0][instruction[0].length()-1] == ':') continue;

    else if (instruction[0] == "mov") registers[instruction[1]] = get_val(instruction[2]);
    else if (instruction[0] == "inc") registers[instruction[1]]++;
    else if (instruction[0] == "dec") registers[instruction[1]]--;

    else if (instruction[0] == "add") registers[instruction[1]] += get_val(instruction[2]);
    else if (instruction[0] == "sub") registers[instruction[1]] -= get_val(instruction[2]);
    else if (instruction[0] == "mul") registers[instruction[1]] *= get_val(instruction[2]);
    else if (instruction[0] == "div") registers[instruction[1]] /= get_val(instruction[2]);

    else if (instruction[0] == "cmp")
    {
        if (registers[instruction[1]] == get_val(instruction[2])) cr = CompareResult::Equals;
        else if (registers[instruction[1]] > get_val(instruction[2])) cr = CompareResult::Greater;
        else if (registers[instruction[1]] < get_val(instruction[2])) cr = CompareResult::Lesser;
    }

    else if (instruction[0][0] == 'j')
    {
      if (instruction[0] == "jnz" && get_val(instruction[1])) i = labels[instruction[2]];
      else if (instruction[0] == "jmp") i = labels[instruction[1]];
      else if (instruction[0] == "je" && cr == 1) i = labels[instruction[1]];
      else if (instruction[0] == "jne" && cr != 1) i = labels[instruction[1]];
      else if ( ( instruction[0] == "jge" && cr == 1 ) || ( instruction[0] == "jle" && cr == 3 ) ) i = labels[instruction[1]];
      else if (instruction[0] == "jge" && cr == 3) i = labels[instruction[1]];
      else if ( ( instruction[0] == "jle" && cr == 1 ) || ( instruction[0] == "jle" && cr == 2 ) ) i = labels[instruction[1]];
      else if (instruction[0] == "jle" && cr == 2) i = labels[instruction[1]];
      cr = CompareResult::Empty;
    }

    else if (instruction[0] == "call")
    {
      lastcall.push_back(i + 1);
      countcalli++;
      i = labels[instruction[1]];
    }

    else if (instruction[0] == "ret" && countcalli != 0)
    {
      countcalli--;
      i = lastcall[countcalli];
      lastcall.erase(lastcall.begin() + countcalli);
    }
  }
  return registers;
}
