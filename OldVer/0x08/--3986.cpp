#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	int count = 0;
	while (N--) {
		string str;
		cin >> str;
		
		stack<char> S;
		for (auto c : str) {
			if (!S.empty() && S.top() == c) {
				S.pop();
			} else {
				S.push(c);
			}
		}
		
		if (S.empty()) {
			count++;
		}
	}
	
	cout << count;
	
	return 0;
}
