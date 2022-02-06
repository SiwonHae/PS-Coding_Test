#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	
	list<char> L;
	for (auto c : s) {
		L.push_back(c);
	}
	auto cur = L.end();
	
	int m;
	cin >> m;
	
	while (m--) {
		char cmd;
		cin >> cmd;
		
		if (cmd == 'L') {
			if (cur != L.begin()) {
				cur--;
			}
		} else if (cmd == 'D') {
			if (cur != L.end()) {
				cur++;
			}
		} else if (cmd == 'B') {
			if (cur != L.begin()) {
				cur--;
				cur = L.erase(cur);
			}
		} else { // cmd == 'P'
			char add;
			cin >> add;
			L.insert(cur, add);
		}
	}
	
	for (auto c : L) {
		cout << c;
	}
	
	return 0;
}