#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	stack<pair<int, int>> S;
	
	for (int i = 0; i < N; i++) {
		int height;
		cin >> height;
		while (!S.empty()) {
			if (S.top().second > height) {
				cout << S.top().first << " ";
				break;
			}
			S.pop();
		}
		
		if (S.empty()) {
			cout << "0 ";
		}
		
		S.push({i + 1, height});
	}
	
	return 0;
}