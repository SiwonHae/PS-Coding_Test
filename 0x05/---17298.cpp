#include <bits/stdc++.h>
using namespace std;

int arr[1000000];
int result[1000000];
stack<int> S;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	for (int i = N - 1; i >= 0; i--) {
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
	
	for (int i = 0; i < N; i++) {
		cout << result[i] << ' ';
	}
	
	return 0;
}