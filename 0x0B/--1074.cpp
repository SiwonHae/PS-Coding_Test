#include <bits/stdc++.h>
using namespace std;

int func(int n, int r, int c) {
	if (n == 0) {
		return 0;
	}
	
	int half = 1 << (n - 1); // 한 변 길이의 절반
	
	if (r < half && c < half) // 1사
		return func(n-1, r, c);
	if (r < half && c >= half) // 2사
		return half * half + func(n - 1, r, c - half);
	if (r >= half && c < half) // 3사
		return 2 * half * half + func(n - 1, r - half, c);
	return 3 * half * half + func(n - 1, r - half, c - half); // 4사
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, r, c;
	cin >> n >> r >> c;
	cout << func(n, r, c);
	
	return 0;
}
