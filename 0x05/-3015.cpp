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
		
		// 현재 사람의 키가 스택의 top보다 크면 현재 사람 이후로 쌍을 이루지 못한다.
		while (!S.empty() && S.top().first < height) {
			ans += S.top().second;
			S.pop();
		}
		
		if (S.empty()) {
			S.push({height, 1});
		} else {
			// 같은 키의 사람
			if (S.top().first == height) {
				int cur = S.top().second;
				S.pop();
				if (!S.empty()) {
					ans++;
				}
				
				ans += cur;
				S.push({height, cur + 1});
			} else { // 더 작은 사람
				ans++;
				S.push({height, 1});
			}
		}
	}
	
	cout << ans;
	
	return 0;
}