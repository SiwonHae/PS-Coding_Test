#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	
	int arr[10002];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	int count = 0;
	
	int start = 0;
	int end = 0;
	int sum = 0;
	
	while (end <= N) {
		if (sum < M) {
			sum += arr[end++];
		} else if (sum > M) {
			sum -= arr[start++];
		} else {
			count++;
			sum += arr[end++];
		}
	}
	
	cout << count;
	
	return 0;
}