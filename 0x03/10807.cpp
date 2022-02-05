#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int arr[102];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	int v;
	cin >> v;
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == v) {
			cnt++;
		}
	}
	
	cout << cnt;
	
	return 0;
}