#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	list<int> L;
	for (int i = 1; i <= n; i++) {
		L.push_back(i);
	}
	auto cur = L.begin();
	
	cout << '<';
	
	int cnt = 1;
	while (cnt < n) {
		for (int i = 0; i < k - 1; i++) {
			cur++;
			
			if (cur == L.end()) {
				cur = L.begin();
			}
		}
		
		cout << *cur << ", ";
		cnt++;
		cur = L.erase(cur);
		
		if (cur == L.end()) {
			cur = L.begin();
		}
	}
	
	cout << *cur << '>';
	
	return 0;
}