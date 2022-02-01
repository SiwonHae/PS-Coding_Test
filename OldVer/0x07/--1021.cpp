#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	
	deque<int> DQ;
	
	int left, right;
	int count = 0;
	
	for (int i = 1; i <= N; i++) {
		DQ.push_back(i);
	}
	
	while (M--) {
		int init;
		cin >> init;
		
		for (int i = 0; i < DQ.size(); i++) {
			if (DQ[i] == init) {
				left = i;
				right = DQ.size() - i;
				break;
			}
		}
		
		// 왼쪽 이동이 더 빠를 때
		if (left < right) {
			while (1) {
				if (DQ.front() == init) {
					break;
				}
				DQ.push_back(DQ.front());
				DQ.pop_front();
				count++;
			}
			DQ.pop_front();
		} 
		// 오른쪽 이동이 더 빠를 때
		else { 
			// left > right 조건은 push, pop 횟수보다 이동획수가 + 1 이므로 count++을 한 번 더해줌.
			count++;
			while (1) {
				if (DQ.back() == init) {
					break;
				}
				DQ.push_front(DQ.back());
				DQ.pop_back();
				count++;
			}
			DQ.pop_back();
		}
	}
	
	cout << count;
	
	return 0;
}

/*
10 3
4 6 9

초기 큐의 상태 (큐 사이즈 10)
= 1 2 3 4 5 6 7 8 9 10

꺼내려는 3개의 값 중 첫 번째 (4)
= 4 5 6 7 8 9 10 1 2 3 (오른쪽으로 데이터 보내기 3)
4를 꺼낸 후
= 5 6 7 8 9 10 1 2 3

꺼내려는 3개의 값 중 두 번째 (6)
= 6 7 8 9 10 1 2 3 5 (오른쪽으로 데이터 보내기 1)
6을 꺼낸 후
= 7 8 9 10 1 2 3 5

꺼내려는 3개의 값 중 세 번째 (9)
= 9 10 1 2 3 5 7 8 (오른쪽으로 데이터 보내기 2)
9를 꺼낸 후
= 10 1 2 3 5 7 8
*/