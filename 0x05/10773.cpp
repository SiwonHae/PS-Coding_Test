#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int k;
	cin >> k;
	
	stack<int> S;
	int sum = 0;
	while (k--) {
		int n;
		cin >> n;
		
		if (n == 0) {
			sum -= S.top();
			S.pop();
		} else {
			sum += n;
			S.push(n);
		}
	}
	
	cout << sum;
	
	return 0;
}