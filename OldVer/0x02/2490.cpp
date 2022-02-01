#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// 배 0, 등 1
	// 윷 배4, 모 등4
	int A, B, C, D;
	int frontCnt = 0, backCnt = 0;
	
	for (int i = 0; i < 3; i++) {
		cin >> A >> B >> C >> D;
		if (A == 0) {
			frontCnt++;
		} else {
			backCnt++;
		}
		if (B == 0) {
			frontCnt++;
		} else {
			backCnt++;
		}
		if (C == 0) {
			frontCnt++;
		} else {
			backCnt++;
		}
		if (D == 0) {
			frontCnt++;
		} else {
			backCnt++;
		}
		
		if (frontCnt == 1 && backCnt == 3) {
			cout << "A \n";
		} else if (frontCnt == 2 && backCnt == 2) {
			cout << "B \n";
		} else if (frontCnt == 3 && backCnt == 1) {
			cout << "C \n";
		} else if (frontCnt == 4) {
			cout << "D \n";
		} else {
			cout << "E \n";
		}
		
		frontCnt = 0, backCnt = 0;
	}
	
	return 0;
}