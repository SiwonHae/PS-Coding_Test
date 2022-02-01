#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int arr[7];
	for (int i = 0; i < 7; i++) {
		cin >> arr[i];
	}
	
	int sum = 0;
	int min = 100;
	for (int i = 0; i < 7; i++) {
		if (arr[i] % 2 == 1) {
			sum += arr[i];
			
			if (arr[i] < min) {
				min = arr[i];
			}
		}
	}
	
	if (sum != 0) {
		cout << sum << '\n';
		cout << min;
	} else {
		cout << "-1";
	}
	
	
	return 0;
}