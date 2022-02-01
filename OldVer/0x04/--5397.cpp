#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int num;
	cin >> num;
	
	for (int i = 0; i < num; i++) {
		list<char> L = {};
		string str;
		auto cursor = L.begin();
		
		cin >> str;
		for (auto c : str) {
			if (c == '<') {
				if (cursor != L.begin()) {
					cursor--;
				}
			} else if (c == '>') {
				if (cursor != L.end()) {
					cursor++;
				}
			} else if (c == '-') {
				if (cursor != L.begin()) {
					cursor--;
					cursor = L.erase(cursor);
				}
			} else {
				L.insert(cursor, c);
			}
		}
		
		for (auto c : L) {
			cout << c;
		}
		cout << '\n';
	}
	return 0;
}