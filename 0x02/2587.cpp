#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int arr[5];
	int sum = 0;
	int avg;
	
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	
	sort(arr, arr + 5);
	avg = sum / 5;
	
	cout << avg << '\n' << arr[2];
	
	return 0;
}