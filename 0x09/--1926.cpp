#include <bits/stdc++.h>
using namespace std;

#define X first // pair에서 first 를 줄여 쓰기 위해
#define Y second // pair에서 second를 줄여쓰기 위해

int board[502][502]; // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[502][502]; // 해당 칸을 방문했는지의 여부를 저장
int n, m; // n = 행의 수, m = 열의 수
int dx[4] = { 1, 0, -1, 0 }; // 상하좌우 4개의 방향을 의미
int dy[4] = { 0, 1, 0, -1 }; // 상하좌우 4개의 방향을 의미

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	
	int mx = 0; // 그림의 넓이 최댓값
	int num = 0; // 그림의 수
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) { // (i, j)를 시작점으로 하고 싶은 상황
			if (board[i][j] == 0 || vis[i][j]) { // 해당 칸이 색칠이 안된 부분(0)이거나 이미 (i, j)를 방문했을 경우 pass
				continue;
			}
			
			// (i, j)는 새로운 그림에 속해있는 시작점
			num++; // 그림의 수 1 증가
			
			queue<pair<int, int>> Q;
			vis[i][j] = 1; // (i, j)로 BFS를 시작하기 위한 준비
			Q.push({ i, j });
			
			int area = 0; // 그림의 넓이
			while (!Q.empty()) {
				area++; // 큐에 들어있는 원소를 하나 뺄 때마다 넓이를 1 증가.
				
				auto cur = Q.front();
				Q.pop();
				
				for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴본다
					int nx = cur.X + dx[dir]; // nx에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
					int ny = cur.Y + dy[dir]; // ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
					
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
						continue; // 범위 밖일 경우에는 pass
					}
					
					if (vis[nx][ny] || board[nx][ny] != 1) {
						continue; // 이미 방문한 칸 or 파란 칸이 아닐 경우 pass
					}
					
					vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
					Q.push({ nx, ny });
				}
			}
			
			// (i, j)를 시작점으로 하는 BFS가 종료
			mx = max(mx, area);
		}
	}
	
	cout << num << '\n' << mx;
	
	return 0;
}
