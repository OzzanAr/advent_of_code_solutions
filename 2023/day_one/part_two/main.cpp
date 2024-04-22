#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<string, int> m{
    {"one", 1},   // 3
    {"two", 2},   // 3
    {"three", 3}, // 5
    {"four", 4},  // 4
    {"five", 5},  // 4
    {"six", 6},   // 3
    {"seven", 7}, // 5
    {"eight", 8}, // 5
    {"nine", 9},  // 4
};

map<int, string> mDigit{
    {1, "one"},
    {2, "two"},
    {3, "three"},
    {4, "four"},
    {5, "five"},
    {6, "six"},
    {7, "seven"},
    {8, "eight"},
    {9, "nine"},
};

void print_map(const map<int, int> &m)
{
  for (const auto &n : m)
    std::cout << "[" << n.first << "] " << n.second << "; ";

  std::cout << '\n';
}

map<int, int> SetupDigitIndicies(string text)
{
  map<int, int> values;
  for (int i = 0; i < text.size(); i++)
  {
    if (isdigit(text[i]))
    {
      values.insert({i, int(text[i] - '0')});
    }
  }

  return values;
}

void CalculatePosition(string foundString, map<int, int> &result, int currentIndex, int position = 0) {
  position = foundString.find(mDigit[currentIndex], position);

  if(position == -1) {
    return;
  }
  
  result[position] = m[mDigit[currentIndex]];
  CalculatePosition(foundString, result, currentIndex, position + 1);
}

void FindWordIndicies(int index, string foundString, map<int, int> &result)
{
  if (index > 9)
  {
    return;
  }

  if (foundString.find(mDigit[index]) != -1)
  {
    CalculatePosition(foundString, result, index);
  }

  FindWordIndicies(index + 1, foundString, result);
}

int main()
{
  string text;
  fstream data("test.txt");
  int sum = 0;
  map<int, int> results;

  while (getline(data, text))
  {
    results = SetupDigitIndicies(text);
    print_map(results);
    FindWordIndicies(1, text, results);
    print_map(results);
  }

  data.close();

  return 0;
}