#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N; // 초기 인원
	int K; // 제거할 차례
	list<int> L = {};
	
	cin >> N >> K;
	
	for (int i = 1; i <= N; i++) {
		L.push_back(i);
	}
	
	auto cursor = L.begin();
	
	cout << '<';
	
	while (L.size() > 1) {
		// K 만큼 이동
		for (int i = 0; i < K - 1; i++) {
			cursor++;
			if (cursor == L.end()) {
				cursor = L.begin();
			}
		}
		
		cout << *cursor << ", ";
		
		cursor = L.erase(cursor);
		if (cursor == L.end()) {
			cursor = L.begin();
		}
	}
	
	cout << *cursor << '>';
	
	return 0;
}