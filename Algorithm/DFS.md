### **들어가며**

 **DFS**는 앞에서 배운 BFS처럼 탐색 알고리즘 중 하나이다. BFS와 구현의 차이점이 있다면 BFS에서는 Queue(큐)를 사용 했지만, DFS에서는 **Stack(스택)**을 사용해서 구현한다.

### **DFS(깊이 우선 탐색) 이란?**

> **깊이 우선 탐색**( - 優先探索, 영어: **depth-first search, DFS**)은 맹목적 탐색방법의 하나로 탐색트리의 최근에 첨가된 노드를 선택하고, 이 노드에 적용 가능한 동작자 중 하나를 적용하여 트리에 다음 수준(level)의 한 개의 자식노드를 첨가하며, 첨가된 자식 노드가 목표노드일 때까지 앞의 자식 노드의 첨가 과정을 반복해 가는 방식이다.  
>   
> \- [위키백과](https://ko.wikipedia.org/wiki/%EA%B9%8A%EC%9D%B4_%EC%9A%B0%EC%84%A0_%ED%83%90%EC%83%89)

### **DFS 알고리즘**

 아래의 사진들을 보고 DFS를 이해해보자.

[##_Image|kage@bXodWh/btrsaRuyoez/kCkjxq9uwbY3VS5P54zJxK/img.png|CDM|1.3|{"originWidth":665,"originHeight":623,"style":"alignCenter","filename":"1.PNG"}_##]

 시작 지점을 1이라고 하자. 1을 방문했다는 표시를 남기고 해당 칸을 스택에 넣는다. 그리고 스택의 top을 pop하고 pop한 칸의 주변(상하좌우)을 탐색하여 방문하지 않았다면 스택에 넣는다.

[##_Image|kage@bC1q4o/btrr3izNv7P/Z6qG4uxljcyRZyjyHVN8K1/img.png|CDM|1.3|{"originWidth":679,"originHeight":606,"style":"alignCenter","filename":"2.PNG"}_##]

 스택의 top인 1을 pop 했으므로 1의 주변인 2와 3을 탐색하여 방문했다는 표시를 남기고 스택에 넣는다.

[##_Image|kage@bJ0JM9/btrr4yive5L/xLq5JnN9IbBSqCgF4cY51k/img.png|CDM|1.3|{"originWidth":637,"originHeight":587,"style":"alignCenter","filename":"3.PNG"}_##]

 스택의 top인 3을 pop 했으므로 3의 주변인 6과 7을 탐색하여 방문했다는 표시를 남기고 스택에 넣는다.

[##_Image|kage@bj59Xv/btrr2yXNFam/Vb9TK1TGZdqz9RPDKIFamk/img.png|CDM|1.3|{"originWidth":642,"originHeight":613,"style":"alignCenter","filename":"4.PNG"}_##]

스택의 top인 7을 pop 했지만 주변에 탐색할 것이 없어서 넘긴다. 그리고 다음 스택의 top인 6 또한 탐색할 것이 없으므로 넘긴다. 그리고 스택의 top인 2를 pop 했으므로 2의 주변인 4와 5를 탐색하여 방문했다는 표시를 남기고 스택에 넣는다.

[##_Image|kage@6Cwh8/btrr1IM0GtY/koti1pRmGOaquRMC7QyIA1/img.png|CDM|1.3|{"originWidth":631,"originHeight":604,"style":"alignCenter","filename":"5.PNG"}_##]

 스택의 top인 5를 pop 했으므로 5의 주변인 9를 탐색하여 방문했다는 표시를 남기고 스택에 넣는다.

[##_Image|kage@bXScaR/btrr9foTd35/XllfXnKZ2Zzo2n3XMHrtZK/img.png|CDM|1.3|{"originWidth":630,"originHeight":603,"style":"alignCenter","filename":"6.PNG"}_##]

 스택의 top인 9를 pop 했지만 주변에 탐색할 것이 없어서 넘긴다. 다음 스택의 top인 4를 pop 했으므로 4의 주변인 8을 탐색하여 방문했다는 표시를 남기고 스택에 넣는다.

[##_Image|kage@daPZrh/btrr125wwLF/QAVrYXDKMi2jhSzHnNYaDK/img.png|CDM|1.3|{"originWidth":647,"originHeight":610,"style":"alignCenter","filename":"7.PNG"}_##]

 스택의 top인 8을 pop 했지만 주변에 탐색할 것이 없어서 넘긴다. 스택이 비었으므로 DFS가 끝났다.

#### **DFS 문제 해결**

1.   시작하는 칸을 방문했다는 표시를 하고 스택에 넣는다.
2.   스택의 top에 있는 원소를 꺼내어(pop) 그 원소의 주변(상하좌우)을 탐색한다. 만약 해당 칸을 이전에 방문했다면 넘어가고, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 스택에 넣는다.
3.   스택이 빌 때까지 계속해서 2번을 반복한다.

\* 모든 칸은 스택에 1번씩 들어가니까 DFS 알고리즘의 시간 복잡도는 칸이 n개라면 **O(n)**이다.

아래의 코드는 DFS를 이해할 수 있는 코드이다.

```
#include <bits/stdc++.h>
using namespace std;

#define X first // pair에서 first 를 줄여 쓰기 위해
#define Y second // pair에서 second를 줄여 쓰기 위해

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
	
	stack<pair<int, int>> S;
	vis[0][0] = 1; // (0, 0) 좌표를 방문했다고 표시
	S.push({0, 0});
	
	while (!S.empty()) {
		pair<int, int> cur = S.top(); // 원소의 주변을 탐색하기 위해 cur를 사용한다.
		S.pop(); // 스택의 top에 있는 원소를 꺼낸다.
		
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
			S.push({nx, ny}); // 해당 칸을 스택에 넣는다.
		}
	}
	
	return 0;
}
```