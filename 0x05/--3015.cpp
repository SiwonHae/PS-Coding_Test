#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	stack<pair<int, int>> S; // 키, 동일한 키를 갖는 사람의 수
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int height;
		cin >> height;
		
		int cur = 1;
		
		while (!S.empty() && S.top().first <= height) {
			if (S.top().first == height) {
				ans += S.top().second;
				cur = S.top().second + 1;
				S.pop();
			} else {
				ans += S.top().second;
				S.pop();
				cur = 1;
			}
		}
		
		if (!S.empty()) {
			ans++;
		}
		
		S.push({height, cur});
	}
	
	cout << ans;
	
	return 0;
}