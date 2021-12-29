#include <bits/stdc++.h>
using namespace std;

#define X first // pair에서 first 를 줄여 쓰기 위해
#define Y second // pair에서 second를 줄여쓰기 위해

int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응

bool vis[502][502]; // 해당 칸을 방문했는지의 여부를 저장
int n = 7, m = 10; // n = 행의 수, m = 열의 수
int dx[4] = { 1, 0, -1, 0 }; // 상하좌우 4개의 방향을 의미
int dy[4] = { 0, 1, 0, -1 }; // 상하좌우 4개의 방향을 의미

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	queue<pair<int, int>> Q;
	vis[0][0] = 1; // (0, 0)을 방문했다고 명시함
	Q.push({ 0, 0 }); // 큐에 시작점인 (0, 0)을 삽입함
	
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		
		cout << '(' << cur.X << ", " << cur.Y << ") -> ";
		for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴본다.
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
	
	return 0;
}
