#include <bits/stdc++.h>
using namespace std;

int n, x;
int arr[10002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> x;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < n; i++) {
		if (arr[i] < x) {
			cout << arr[i] << ' ';
		}
	}
	
	return 0;
}