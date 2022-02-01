#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B, C;
	cin >> A >> B >> C;
	
	int E, F, G;
	E = max({ A, B, C }); // 최댓값
	F = min({ A, B, C }); // 최솟값
	G = A + B + C - E - F;
	
	cout << F << ' ' << G << ' ' << E;
	
	return 0;
}