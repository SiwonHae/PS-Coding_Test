#include <bits/stdc++.h>
using namespace std;

// https://cocoon1787.tistory.com/376 참고
int func(int n, int r, int c) {
	if (n == 0) {
		return 0;
	}
	
	int half = 1 << (n - 1); // 한 변 길이의 절반
	
	if (r < half && c < half) // 1사
		return half * half * 0 + func(n - 1, r, c);
	else if (r < half && c >= half) // 2사
		return half * half * 1 + func(n - 1, r, c - half);
	else if (r >= half && c < half) // 3사
		return half * half * 2 + func(n - 1, r - half, c);
	else // 4사
		return half * half * 3 + func(n - 1, r - half, c - half); 
	
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, r, c;
	cin >> n >> r >> c;
	cout << func(n, r, c);
	
	return 0;
}
