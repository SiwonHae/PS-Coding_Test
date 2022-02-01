#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int sum = 0;
	int arr[9];
	
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + 9);
	
	// 9명에서 2명 뺏을 때 합이 100이 된다.
	
	int f1, f2;
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - arr[i] - arr[j] == 100) {
				f1 = i;
				f2 = j;
			}
		}
	}
	
	for (int i = 0; i < 9; i++) {
		if (i == f1 || i == f2) {
			continue;
		}
		cout << arr[i] << '\n';
	}
	
	return 0;
}