#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[1002];
int dist1[1002][1002]; // 불의 전파 시간
int dist2[1002][1002]; // 지훈이의 이동 시간
int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		fill(dist1[i], dist1[i] + m, -1);
		fill(dist2[i], dist2[i] + m, -1);
	}
	
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	
	queue<pair<int, int>> Q1; // 불 BFS
	queue<pair<int, int>> Q2; // 지훈 BFS
	
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
	while (!Q1.empty()) {
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
			Q1.push({ nx, ny });
		}
	}
	
	// 지훈 BFS
	while (!Q2.empty()) {
		pair<int, int> cur = Q2.front();
		Q2.pop();
		
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				// 범위를 벗어남 -> 탈출 성공 -> 큐에 거리순으로 들어감으로 최초로 탈출한 시간이 정답.
				cout << dist2[cur.X][cur.Y] + 1;
				return 0;
			}
			if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') {
				continue;
			}
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) {
				// 자신이 도착한 시간과 동시에 불이 도착하거나 혹은 자신보다 더 빨리 불이 도착하는 자리로는 갈 수 없음.
				continue;
			}
			
			dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
			Q2.push({ nx, ny });
		}
	}
	
	cout << "IMPOSSIBLE";
	
	return 0;
}
