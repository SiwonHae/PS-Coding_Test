#include <iostream>
#include <stack>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int ans = 0;
  stack<int> S;
  while (n--) {
    int x;
    cin >> x;
    S.push(x);
  }

  int current = 0;
  while (!S.empty()) {
    if (current < S.top()) {
      current = S.top();
      ans++;
    }
    S.pop();
  }

  cout << ans;
  
  return 0;
}