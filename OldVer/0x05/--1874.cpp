#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<int> S;
	string result = "";
	int cnt = 1;
	int n;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int init;
		cin >> init;
		
		while (cnt <= init) {
			S.push(cnt);
			cnt++;
			result += "+\n";
		}
		
		if (S.top() == init) {
			S.pop();
			result += "-\n";
		} else {
			cout << "NO";
			return 0;
		}
	}
	
	cout << result;
	
	return 0;
}