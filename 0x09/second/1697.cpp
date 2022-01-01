#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, k;
int dist[100002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	
	fill(dist, dist + 100001, -1); // dist 배열 -1 초기화
	dist[n] = 0; // 시작 지점은 거리가 0부터 시작
	
	queue<int> Q;
	Q.push(n);
	
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		
		for (int nxt : {cur - 1, cur + 1, cur * 2}) {
			if (nxt < 0 || nxt > 100000) {
				// 범위 벗어나면 pass
				continue;
			}
			if (dist[nxt] != -1) {
				// 이미 방문했으면 pass
				continue;
			}
			
			dist[nxt] = dist[cur] + 1;
			Q.push(nxt);
		}
	}
	
	cout << dist[k];
	
	return 0;
}
