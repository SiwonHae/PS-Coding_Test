#include <bits/stdc++.h>
using namespace std;

void func(int start, int end, int n) {
	// start = 1, end = 3
	int middle = 6 - start - end; // 2
	
	if (n == 1) { // base condition
		cout << start << " " << end << '\n';
        return;
	}
	
	func(start, middle, n - 1); // 1번 기둥의 n - 1개 => 2번 기둥으로 옮긴다. 2번 기둥(6 - a - b)
	cout << start << " " << end << '\n'; // 1번 기둥의 n번 원판을 3번 기둥으로 옮긴다.
	func(middle, end, n - 1); // 2번 기둥의 n - 1개 => 3번 기둥으로 옮긴다. 2번 기둥(6 - a - b)
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	cout << (1 << n) - 1 << '\n'; // 2^n - 1
	func(1, 3, n);
	
	return 0;
}
