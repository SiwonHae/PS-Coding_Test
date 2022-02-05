#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int student[2][6] = {};
	
	int n, k;
	cin >> n >> k;
	
	while (n--) {
		int s, y;
		cin >> s >> y;
		student[s][y - 1]++;
	}
	
	int ans = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			ans += student[i][j] / k;
			if (student[i][j] % k != 0) {
				ans++;
			}
		}
	}
	
	cout << ans;
	
	return 0;
}