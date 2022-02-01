#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int sum = 0;
	int mini;
	int cnt = 0;
	
	for (int i = 0; i < 7; i++) {
		int n;
		cin >> n;
		
		if (n % 2 != 0) {
			if (cnt == 0) {
				mini = n;
			}
			sum += n;
			mini = min(mini, n);
			cnt++;
		}
	}
	
	if (cnt == 0) {
		cout << "-1";
	} else {
		cout << sum << '\n' << mini;
	}
	
	return 0;
}