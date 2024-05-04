#include <iostream>
#include <stack>
using namespace std;

bool match(char a, char b) {
  if (a == '(' && b != ')') return false;
  if (a == '[' && b != ']') return false;
  if (a == '{' && b != '}') return false;

  return true;
}

int main() {
  int n;
  cin >> n;
  cin.ignore();

  string input;
  getline(cin, input);

  stack<char> open;
  
  for (int i = 0; i < n; ++i) {
    char c = input[i];

    if (c == '(' || c == '[' || c == '{') {
      open.push(c);
    } else if (c != ' ') {
      if (!open.empty() && match(open.top(), c)) {
        open.pop();
      } else {
        cout << c << " " << i << "\n";
        return 0;
      }
    }
  }

  cout << "ok so far\n";

  return 0;
}
