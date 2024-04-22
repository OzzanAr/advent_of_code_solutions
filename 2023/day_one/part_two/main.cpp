#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<int, string> digitWordmap{
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
  position = foundString.find(digitWordmap[currentIndex], position);

  if(position == -1) {
    return;
  }
  
  result[position] = currentIndex;
  CalculatePosition(foundString, result, currentIndex, position + 1);
}

void FindWordIndicies(int index, string foundString, map<int, int> &result)
{
  if (index > 9)
  {
    return;
  }

  if (foundString.find(digitWordmap[index]) != -1)
  {
    CalculatePosition(foundString, result, index);
  }

  FindWordIndicies(index + 1, foundString, result);
}

int main()
{  
  int sum = 0;
  int first, last;
  string text;
  fstream data("input.txt");
  map<int, int> results;

  while (getline(data, text))
  {
    results = SetupDigitIndicies(text);
    FindWordIndicies(1, text, results);
    auto first_element = results.begin(); // Iterator to first element
    auto last_element = prev(results.end()); // Iterator to last element

    first = first_element->second;
    last = last_element->second;
            
    first = stoi(to_string(first) + to_string(last));
    sum += first;
  }

  cout << sum << endl;

  data.close();

  return 0;
}