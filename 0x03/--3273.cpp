#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int input[n];
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	int x;
	cin >> x;
	
	sort(input, input + n);
	int left = 0;
	int right = n - 1;
	int result = 0;
	while (left < right) {
		if (input[left] + input[right] == x) {
			result++;
			right--;
		} else if (input[left] + input[right] > x) {
			right--;
		} else { // input[left] + input[right] < x
			left++;
		}
	}
	
	cout << result;
	
	return 0;
}