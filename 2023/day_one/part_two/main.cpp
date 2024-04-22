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

void FindWordIndicies(int index, string foundString, map<int, int> &result, int counter = 0)
{
  if (index > 9)
  {
    return;
  }

  int pos = foundString.find(mDigit[index]);

  if (pos != -1)
  {
    // cout << foundString << endl;
    foundString.erase(pos + 1, 1);
    result[pos] = m[mDigit[index]];
    FindWordIndicies(index, foundString, result, counter);
  }

  FindWordIndicies(index + 1, foundString, result, counter);
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

  //  FindWordIndicies(1, text, results);

  data.close();

  return 0;
}