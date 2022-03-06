#include <iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int arr[2000001] = {};

  int number;
  for (int i = 0; i < n; i++) {
    cin >> number;
    arr[number] = 1; // 숫자가 존재한다고 표시함.
  }

  int x;
  cin >> x;

  int ans = 0;
  for (int i = 1; i < (x + 1) / 2; i++) {
    if (arr[i] == 1 && arr[x - i] == 1) {
      ans++;
    }
  }    

  cout << ans;
  
  return 0;
}