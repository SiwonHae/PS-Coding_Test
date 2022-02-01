#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	int arr[201] = {}; // -100 ~ 100 까지 인덱스!
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr[input + 100]++;
	}
	int v;
	cin >> v;
	
	int result;
	result = arr[v + 100];
	cout << result;
	
	return 0;
}