### **들어가며**

 **BFS**는 코딩테스트에 자주 사용되는 알고리즘이다. Flood Fill과 같은 문제들을 해결하는 데 사용할 수 있다. 이를 구현하기 위해서는 **Queue(큐)**를 사용한다!

### **BFS(너비 우선 탐색) 이란?**

> **너비 우선 탐색(Breadth-first search, BFS)**은 맹목적 탐색방법의 하나로 시작 정점을 방문한 후 시작 정점에 인접한 모든 정점들을 우선 방문하는 방법이다. 더 이상 방문하지 않은 정점이 없을 때까지 방문하지 않은 모든 정점들에 대해서도 너비 우선 검색을 적용한다. OPEN List는 큐를 사용해야만 레벨 순서대로 접근이 가능하다.  
>   
> \- [위키백과](https://ko.wikipedia.org/wiki/%EB%84%88%EB%B9%84_%EC%9A%B0%EC%84%A0_%ED%83%90%EC%83%89)

### **BFS 알고리즘**

 아래의 사진들을 보고 BFS를 이해해보자.

[##_Image|kage@mBf6O/btrrlTB1K4s/FUWWSknuUKHKipwe4nMbUk/img.png|CDM|1.3|{"originWidth":597,"originHeight":516,"style":"alignCenter","filename":"1.PNG"}_##]

 시작 지점이 1이라고 하자. 그러면 1에 방문했다는 표시를 남기고 해당 칸을 큐에 넣는다. 그리고 큐가 빌 때까지 큐의 front를 빼고 뺀 좌표의 주변(상하좌우)을 탐색하여 방문하지 않았다면 큐에 넣어준다.

[##_Image|kage@1qPz4/btrrqmoTPig/sCYFKau2ocSY2uqPIc60Wk/img.png|CDM|1.3|{"originWidth":579,"originHeight":519,"style":"alignCenter","filename":"2.PNG"}_##]

 큐의 front인 1을 삭제하고 1의 주변인 2와 3을 탐색했으므로 이 칸들을 방문했다는 표시를 남기고 큐에 넣는다.

[##_Image|kage@AtGhF/btrrpTN2iPr/Fk8K2K3FSyq5NhcjCMau5k/img.png|CDM|1.3|{"originWidth":600,"originHeight":517,"style":"alignCenter","filename":"3.PNG"}_##]

 큐의 front인 2를 삭제하고 2의 주변인 4와 5를 탐색했으므로 이 칸들을 방문했다는 표시를 남기고 큐에 넣는다.

[##_Image|kage@bAsVro/btrrlTaZPJw/klbTjdZJPDokKTpeK0kLhK/img.png|CDM|1.3|{"originWidth":589,"originHeight":522,"style":"alignCenter","filename":"4.PNG"}_##]

 큐의 front인 3을 삭제하고 3의 주변인 6과 7을 탐색했으므로 이 칸들을 방문했다는 표시를 남기고 큐에 넣는다.

[##_Image|kage@bxMfkU/btrroWLg3ZA/rqN6CU4ghkAneoojRKz3nk/img.png|CDM|1.3|{"originWidth":597,"originHeight":515,"style":"alignCenter","filename":"5.PNG"}_##]

 큐의 front인 4를 삭제하고 4의 주변인 8을 탐색했으므로 이 칸을 방문했다는 표시를 남기고 큐에 넣는다.

[##_Image|kage@ypZzW/btrrpnIDwJM/akrgdpodMYrhuwbOawQTq1/img.png|CDM|1.3|{"originWidth":581,"originHeight":520,"style":"alignCenter","filename":"6.PNG"}_##]

큐의 front인 5를 삭제하고 5의 주변인 9를 탐색했으므로 이 칸을 방문했다는 표시를 남기고 큐에 넣는다.

[##_Image|kage@cKTv8P/btrrq0TrHZn/uUFD0BoniKt5Piu7gK4aVK/img.png|CDM|1.3|{"originWidth":570,"originHeight":496,"style":"alignCenter","filename":"7.PNG"}_##]

 나머지들도 똑같은 과정으로 큐의 front를 확인하는 등의 과정을 했는데 해당 주변의 좌표들을 모두 방문했으므로 큐에서 삭제한다.

#### **BFS 문제 해결**

1.   시작하는 칸을 방문했다는 표시를 하고 큐에 넣는다.
2.   큐의 front에 있는 원소를 꺼내어(pop) 그 원소의 주변(상하좌우)을 탐색한다. 만약 해당 칸을 이전에 방문했다면 넘어가고, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 큐에 넣는다.
3.   큐가 빌 때까지 계속해서 2번을 반복한다.

\* 모든 칸은 큐에 1번씩 들어가니까 BFS 알고리즘의 시간 복잡도는 칸이 n개라면 **O(n)**이다. 만약에 행이 r개, 열이 c개라면 시간 복잡도는 **O(rc)**이다.

아래의 코드는 BFS를 이해할 수 있는 코드이다.

```
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
	vis[0][0] = 1; // (0, 0) 좌표를 방문했다고 표시
	Q.push({0, 0}); // 큐에 시작 좌표(0, 0)를 넣는다.
	
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); // 원소의 주변을 탐색하기 위해 cur를 사용한다.
		Q.pop(); // 큐의 front에 있는 원소를 꺼낸다.
		
		cout << '(' << cur.X << ", " << cur.Y << ") -> ";
		
		for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 탐색한다.
			int nx = cur.X + dx[dir]; // nx에 dir에서 정한 방향(상하좌우)의 인접한 칸의 좌표가 들어간다.
			int ny = cur.Y + dy[dir]; // ny에 dir에서 정한 방향(상하좌우)의 인접한 칸의 좌표가 들어간다.
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) { 
				continue; // 범위를 벗어날 경우에는 넘어간다.
			}
			if (vis[nx][ny] || board[nx][ny] != 1) {
				continue; // 이미 방문한 칸이거나 방문할 필요가 없는(빨간 칸)일 경우 넘어간다.
			}
			
			vis[nx][ny] = 1; // (nx, ny) 좌표를 방문했다고 표시한다.
			Q.push({nx, ny}); // 해당 칸을 큐에 넣는다.
		}
	}
	
	return 0;
}
```