#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, K;
	cin >> N >> K;
	
	int student[2][6] = {};
	int gender, grade;
	for (int i = 0; i < N; i++) {
		cin >> gender >> grade;
		student[gender][grade - 1]++;
	}
	
	int result = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			// 나눈 몫 = 방의 개수
			result += student[i][j] / K;
			
			// 나머지 있을 시 방 추가
			if (student[i][j] % K != 0) {
				result++;
			}
		}
	}
	
	cout << result;
	
	return 0;
}