#include <iostream>
#include <list>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  
  list<int> L;

  int number;
  for (int i = 1; i <= n; i++) {
    cin >> number;

    auto cur = L.end();
    for (int j = 0; j < number; j++) {
      cur--;
    }
    
    L.insert(cur, i);
  }

  for (auto i : L) {
    cout << i << ' ';
  }
  
  return 0;
}