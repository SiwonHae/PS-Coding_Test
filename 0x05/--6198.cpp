#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<int> S;
	long long result;
	
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		long long init;
		cin >> init;
		
		while (!S.empty() && S.top() <= init) {
			S.pop();
		}
		
		result += S.size();
		S.push(init);
	}
	
	cout << result;
	
	return 0;
}