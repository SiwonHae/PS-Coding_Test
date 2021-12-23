#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	int input[N];
	for (int i = 0; i < N; i++) {
		cin >> input[i]; 
	}
	int v;
	cin >> v;
	
	int result = 0;
	for (int i = 0; i < N; i++) {
		if (input[i] == v) {
			result++;
		}
	}
	
	cout << result;
	
	return 0;
}