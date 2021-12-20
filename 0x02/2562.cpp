#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int max = 0, idx, input;
	for (int i = 0; i < 9; i++) {
		cin >> input;
		
		if (input > max) {
			max = input;
			idx = i;
		}
	}
	
	cout << max << '\n';
	cout << idx + 1;
	
	return 0;
}