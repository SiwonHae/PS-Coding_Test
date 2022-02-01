#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B, C;
	cin >> A >> B >> C;
	
	int sameNum, count = 0;
	if (A == B) {
		sameNum = A;
		count++;
	} else if (B == C) {
		sameNum = B;
		count++;
	}
	
	if (A == C) {
		sameNum = A;
		count++;
	}
	
	if (count == 2) {
		cout << 10000 + sameNum * 1000;
	} else if (count == 1) {
		cout << 1000 + sameNum * 100;
	} else {
		cout << max({ A, B, C }) * 100;
	}
	
	return 0;
}