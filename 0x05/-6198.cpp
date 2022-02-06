#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	stack<int> S;
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		long long height;
		cin >> height;
		
		while (!S.empty() && S.top() <= height) {
			S.pop();
		}
		
		sum += S.size();
		
		S.push(height);
	}
	
	cout << sum;
	
	return 0;
}