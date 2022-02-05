#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;

	int alphabet[26] = {};
	
	for (int i = 0; i < s.length(); i++) {
		alphabet[s[i] - 'a']++;
	}
	
	for (int i = 0; i < 26; i++) {
		cout << alphabet[i] << ' ';
	}
	
	return 0;
}