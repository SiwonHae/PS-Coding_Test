#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int arr[100002];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort (arr, arr + n);
	
	int x;
	cin >> x;
	
	int count = 0;
	int start = 0;
	int end = n - 1;
	int sum = 0;
	
	while (start < end) {
		if (arr[start] + arr[end] == x) {
			count++;
			end--;
		} else if (arr[start] + arr[end] > x) {
			end--;
		} else { // arr[start] + arr[end] < x
			start++;
		}
	}
	
	cout << count;
	
	return 0;
}