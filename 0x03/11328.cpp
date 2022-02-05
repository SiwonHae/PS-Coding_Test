#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	string s1, s2;
	bool isPossible = true;
	for (int i = 0; i < n; i++) {
		cin >> s1 >> s2;
		
		// 알파벳 개수로 파악하자.
		int alphabet1[26] = {};
		int alphabet2[26] = {};
		isPossible = true;
		
		for (int i = 0; i < s1.length(); i++) {
			alphabet1[s1[i] - 'a']++;
		}
		for (int i = 0; i < s2.length(); i++) {
			alphabet2[s2[i] - 'a']++;
		}
		
		for (int i = 0; i < 26; i++) {
			if (alphabet1[i] != alphabet2[i]) {
				isPossible = false;
				break;
			}
		}
		
		if (isPossible) {
			cout << "Possible \n";
		} else {
			cout << "Impossible \n";
		}
	}
	
	return 0;
}