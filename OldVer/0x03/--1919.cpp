#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string str1, str2;
	cin >> str1 >> str2;
	
	int arr1[26] = {};
	int arr2[26] = {};
	for (int i = 0; i < str1.length(); i++) {
		arr1[str1[i] - 'a']++;
	}
	for (int i = 0; i < str2.length(); i++) {
		arr2[str2[i] - 'a']++;
	}
	
	int count = 0;
	for (int i = 0; i < 26; i++) {
		if (arr1[i] != arr2[i]) {
			count += abs(arr1[i] - arr2[i]);
		}
	}
	
	cout << count;
	
	return 0;
}