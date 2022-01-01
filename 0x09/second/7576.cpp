#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[1002][1002];
int dist[1002][1002];
int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	
	queue<pair<int, int>> Q;
	// 0 = 익지 않은, 1 = 익은, -1 = 벽
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			
			if (board[i][j] == 1) {
				Q.push({i, j});
			}
			if (board[i][j] == 0) {
				dist[i][j] = -1;
				// 안익은 토마토 -1, 익은 토마토와 벽은 0 이다.
			}
		}
	}
	
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			
			if (dist[nx][ny] >= 0) {
				continue;
			}
			
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({nx, ny});
		}
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == -1) {
				cout << -1;
				return 0;
			}
			
			ans = max(ans, dist[i][j]);
		}
	}
	
	cout << ans;
	return 0;
}
