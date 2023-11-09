#include <iostream>
#include <list>
using namespace std;

int main()
{
  int n;
  cin >> n;

  list<string> list;
  for (int i = 0; i < n; ++i)
  {
    string name;
    cin >> name;
    list.push_back(name);
  }

  int operations;
  cin >> operations;

  for (int i = 0; i < operations; ++i)
  {
    string op;
    cin >> op;
    if (op == "leave")
    {
      string name;
      cin >> name;
      for (auto it = list.begin(); it != list.end(); ++it)
      {
        if (*it == name)
        {
          list.erase(it);
          break;
        }
      }
    }
    else
    {
      string cutter, cuttee;
      cin >> cutter >> cuttee;
      for (auto it = list.begin(); it != list.end(); ++it)
      {
        if (*it == cuttee)
        {
          list.insert(it, cutter);
          break;
        }
      }
    }
  }

  for (auto &name : list)
  {
    cout << name << "\n";
  }

  return 0;
}
