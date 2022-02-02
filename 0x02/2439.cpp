#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			cout << ' ';
		}
		for (int k = 0; k <= i; k++) {
			cout << '*';
		}
		
		cout << '\n';
	}
	
	return 0;
}