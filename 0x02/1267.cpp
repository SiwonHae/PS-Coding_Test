#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int arr[20] = {};
	int yMoney = 0;
	int mMoney = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		
		// 영식 요금
		yMoney += (arr[i] / 30 + 1) * 10;
		// 민식 요금
		mMoney += (arr[i] / 60 + 1) * 15;
	}
	
	if (yMoney > mMoney) {
		cout << "M " << mMoney;
	} else if (yMoney < mMoney) {
		cout << "Y " << yMoney;
	} else {
		cout << "Y M " << yMoney;
	}
	
	return 0;
}