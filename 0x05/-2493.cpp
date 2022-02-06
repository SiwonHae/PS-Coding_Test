#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	stack<pair<int, int>> S;
	for (int i = 1; i <= n; i++) {
		int height;
		cin >> height;
		
		while (!S.empty()) {
			// 스택의 top이 현재 입력한 값보다 크면 신호를 받을 수 있다.
			if (S.top().second > height) {
				cout << S.top().first << ' ';
				break;
			} else {
				// 스택의 top이 현재 입력한 값보다 작으면 신호를 받을 수 없으므로 필요없다.
				S.pop();
			}
		}
		
		if (S.empty()) {
			cout << "0 ";
		}
		
		S.push({i, height});
	}
	
	return 0;
}