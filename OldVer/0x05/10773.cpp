#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int K;
	cin >> K;
	
	stack<int> S;
	int result = 0;
	
	for (int i = 0; i < K; i++) {
		int init;
		cin >> init;
		
		if (init == 0) {
			if (S.empty()) {
				continue;
			} else {
				S.pop();
			}
		} else {
			S.push(init);
		}
	}
	
	while (!S.empty()) {
		result += S.top();
		S.pop();
	}
	
	cout << result;
	
	return 0;
}