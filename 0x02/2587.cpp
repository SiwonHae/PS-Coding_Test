#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[5];
	int avg, center, sum = 0;
	
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	avg = sum / 5;
	
	sort(arr, arr + 5);
	
	cout << avg << '\n';
	cout << arr[2];
	
	return 0;
}