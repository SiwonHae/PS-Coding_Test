#include <iostream>
#include <stack>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  getline(cin, s);
  
  bool isTag = false;
  stack<char> S;
  
  for (auto c : s) {
    if (c == '<') {
      while (!S.empty()) {
        cout << S.top();
        S.pop();
      }
      isTag = true;
      cout << c;
    } else if (c == '>') {
      isTag = false;
      cout << c;
    } else if (c == ' ') {
      while (!S.empty()) {
        cout << S.top();
        S.pop();
      }
      cout << c;
    } else if (isTag) {
      cout << c;
    } else {
      S.push(c);
    }
  }

  while (!S.empty()) {
    cout << S.top();
    S.pop();
  }
  cout << '\n';
  
  return 0;
}