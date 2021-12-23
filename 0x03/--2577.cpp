#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int A, B, C;
	cin >> A >> B >> C;
	int total = A * B * C;
	
	int result[10] = {};
	while (total > 0) {
		result[total % 10]++;
		total /= 10;
	}
	
	for (int i = 0; i < 10; i++) {
		cout << result[i] << '\n';
	}
	
	return 0;
}