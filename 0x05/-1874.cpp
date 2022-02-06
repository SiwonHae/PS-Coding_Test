#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	stack<int> S;
	vector<char> result;
	int idx = 1;
	
	while (n--) {
		int x;
		cin >> x;
		
		while (idx <= x) {
			S.push(idx);
			idx++;
			result.push_back('+');
		}
		
		if (S.top() == x) {
			S.pop();
			result.push_back('-');
		} else {
			cout << "NO";
			return 0;
		}
	}
	
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}
	
	return 0;
}