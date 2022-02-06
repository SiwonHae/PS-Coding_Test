#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int arr[1000002] = {};
	int result[1000002] = {};
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	stack<int> S;
	
	for (int i = n - 1; i >= 0; i--) {
		while (!S.empty() && S.top() <= arr[i]) {
			S.pop();
		}
		
		if (S.empty()) {
			result[i] = -1; 
		} else {
			result[i] = S.top();
		}
		
		S.push(arr[i]);
	}
	
	for (int i = 0; i < n; i++) {
		cout << result[i] << ' ';
	}
	
	return 0;
}