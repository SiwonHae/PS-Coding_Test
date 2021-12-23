#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	int result[10] = {};
	while (N > 0) {
		result[N % 10]++;
		N /= 10;
	}
	
	// 0 ~ 9 까지 각각 1개씩 가진 것이 한 세트 (6과 9는 혼용 가능)
	int set = 1; // 기본 1세트
	
	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9) {
			continue;
		}
		set = max(set, result[i]);
	}
	
	// (result[6] + result[9]) / 2를 올림한 값이 6, 9에 대한 필요한 세트의 수임.
	set = max(set, (result[6] + result[9] + 1) / 2);
	
	cout << set;
	
	return 0;
}