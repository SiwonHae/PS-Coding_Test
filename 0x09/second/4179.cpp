#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[1002];
int dist1[1002][1002]; // 불 이동 시간
int dist2[1002][1002]; // 지훈이 이동 시간
int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	
	// dist 배열 -1로 초기화!
	for (int i = 0; i < n; i++) {
		fill(dist1[i], dist1[i] + m, -1);
		fill(dist2[i], dist2[i] + m, -1);
	}
	
	queue<pair<int, int>> Q1;
	queue<pair<int, int>> Q2;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'F') {
				Q1.push({ i, j });
				dist1[i][j] = 0;
			}
			if (board[i][j] == 'J') {
				Q2.push({i, j});
				dist2[i][j] = 0;
			}
		}
	}
	
	// 불 BFS
	while(!Q1.empty()) {
		pair<int, int> cur = Q1.front();
		Q1.pop();
		
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			
			if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') {
				continue;
			}
			
			dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
			Q1.push({nx, ny});
		}
	}
	
	// 지훈 BFS
	while(!Q2.empty()) {
		pair<int, int> cur = Q2.front();
		Q2.pop();
		
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				cout << dist2[cur.X][cur.Y] + 1;
				return 0;
			}
			
			if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') {
				continue;
			}
			
			// 불 BFS를 돌려서 나온 불의 이동 시간 조건
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) {
				// dist1[nx][ny] != -1 조건은 불이 번졌다는 것!
				// dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1 조건은 지훈이가 도착한 시간과 동시에 불이 도착(=) 하거나 지훈이보다 더 빨리 불이 도착(<) 한 경우에는 이동 불가!
				continue;
			}
			
			dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
			Q2.push({nx, ny});
		}
	}
	
	cout << "IMPOSSIBLE";
	
	return 0;
}
