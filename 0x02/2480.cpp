#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, c;
	cin >> a >> b >> c;
	
	int ans = 0;
	if (a == b && b == c) {
		ans = 10000 + a * 1000;
	} else if (abs(a - b) == 0 || abs(a - c) == 0 || abs(b - c) == 0) {
		if (abs(a - b) == 0) {
			ans = 1000 + a * 100;
		} else if (abs(a - c) == 0) {
			ans = 1000 + a * 100;
		} else {
			ans = 1000 + b * 100;
		}
	} else {
		ans = max(max(a, b), c) * 100;
	}
	
	cout << ans;
	
	return 0;
}