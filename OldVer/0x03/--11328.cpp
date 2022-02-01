#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	string str1, str2;
	int arr[26] = {};
	bool isPossible;
	
	for (int i = 0; i < N; i++) {
		cin >> str1 >> str2;
		isPossible = true;
		fill(arr, arr + 26, 0);
		
		for (int j = 0; j < str1.length(); j++) {
			arr[str1[j] - 'a']++;
			arr[str2[j] - 'a']--;
		}
		
		for (int j = 0; j < 26; j++) {
			if (arr[j] != 0) {
				isPossible = false;
				break;
			}
		}
		
		if (isPossible) {
			cout << "Possible" << '\n';
		} else {
			cout << "Impossible" << '\n';
		}
	}
	
	return 0;
}