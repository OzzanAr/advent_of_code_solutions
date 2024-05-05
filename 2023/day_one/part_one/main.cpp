#include <iostream>
#include <fstream>

using namespace std;

string readFromStart(string text)
{
  for (int i = 0; i < text.size(); i++)
  {
    if (isdigit(text[i]))
    {
      string s(1, text[i]);
      return s;
    }
  }

  return "nah";
}

string readFromEnd(string text)
{
  for (int i = text.size() - 1; i >= 0; i--)
  {
    if (isdigit(text[i]))
    {
      string s(1, text[i]);
      return s;
    }
  }

  return "nah";
}

int main()
{
  string text;
  string start, end;
  fstream data("input.txt");
  int sum = 0;

  while (getline(data, text))
  {
    start = readFromStart(text);
    end = readFromEnd(text);
    sum += stoi(start.append(end));
  }

  data.close();
  cout << sum << "\n";
  return 0;
}