#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, arr[20];
	int tempY, tempM;
	int moneyY = 0, moneyM = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		
		// 영식 요금제
		tempY = arr[i] / 30;
		moneyY += (tempY + 1) * 10;
		
		// 민식 요금제
		tempM = arr[i] / 60;
		moneyM += (tempM + 1) * 15;
	}
	
	if (moneyY == moneyM) {
		cout <<"Y M "<< moneyY;
	} else if (moneyY > moneyM) {
		cout << "M "<<moneyM;
	} else {
		cout <<"Y "<<moneyY;
	}
	
	return 0;
}