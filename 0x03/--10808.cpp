#include <bits/stdc++.h>
using namespace std;

int str[26];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	
	
	for (int i = 0; i < s.size(); i++) {
		str[s[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		cout << str[i] << ' ';
	}
	
	return 0;
}