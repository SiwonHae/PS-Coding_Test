#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << '*';
		}
		for (int k = 1; k <= 2 * n - 2 * i; k++) {
			cout << ' ';
		}
		for (int y = 1; y <= i; y++) {
			cout << '*';
		}
		cout << '\n';
	}
	
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			cout << '*';
		}
		for (int k = 2 * n - 2 * i; k >= 1; k--) {
			cout << ' ';
		}
		for (int y = 1; y <= i; y++) {
			cout << '*';
		}
		cout << '\n';
	}
	
	return 0;
}