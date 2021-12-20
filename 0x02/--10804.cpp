#include <bits/stdc++.h>

using namespace std;

int arr[20];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 20; i++) {
		arr[i] = i + 1;
	}
	
	int a, b;
	for (int i = 0; i < 10; i++) {
		cin >> a >> b;
		reverse(arr + a - 1, arr + b);
	}
	
	for (int i = 0; i < 20; i++) {
		cout << arr[i] << ' ';
	}
	
	return 0;
}