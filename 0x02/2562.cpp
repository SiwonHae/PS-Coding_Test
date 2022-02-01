#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int arr[9];
	int mx = 0;
	int idx = 0;
	
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		if (mx < arr[i]) {
			mx = arr[i];
			idx = i + 1;
		}	
	}
	
	cout << mx << '\n' << idx;
	
	return 0;
}