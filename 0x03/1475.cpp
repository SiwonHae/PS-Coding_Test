#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int set = 1; // 기본 세트 1개
	
	int arr[10] = {};
	// 숫자 개수 파악
	while (n > 0) {
		int tmp = n % 10;
		arr[tmp]++;
		n /= 10;
	}
	
	int specNum = arr[6] + arr[9]; // 6과 9의 개수 합
	if (specNum % 2 != 0) {
		specNum /= 2;
		specNum++;
	}  else {
		specNum /= 2;
	}
	
	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9) {
			continue;
		}
		set = max(arr[i], set);
	}
	
	set = max(set, specNum);
	
	cout << set;
	
	return 0;
}