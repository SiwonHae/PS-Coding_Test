### **들어가며**

 [백준 3273번](https://www.acmicpc.net/problem/3273) 문제를 해결하려는 데 2중 for문으로 코드를 짜서 제출하면 시간 초과가 나서 이에 대한 해결방안을 알아보게 되었다. **투 포인터(Two Pointers)**로 해결하면 쉽게 해결할 수 있다는 것을 알고 이에 대해 설명한다.

### **투 포인터란?**

>  **투 포인터(Two Pointers)**는 1차원 배열에서 두 개의 포인터를 조작하여 원하는 결과를 얻는 알고리즘을 말한다. 이처럼 두 개의 포인터를 사용하면 반복문을 여러번 시행하는 것 보다 시간을 효율적으로 사용할 수 있다.  
>   
>  최악의 경우에도 두 개의 포인터가 배열의 마지막 인덱스로 오게 된다. 따라서 시간 복잡도는 **O(n)**이다.

### **투 포인터 알고리즘**

 [백준 2003번](https://www.acmicpc.net/problem/2003) 문제를 예시로 알고리즘을 이해해보자.

 이 문제에서는 N까지의 배열이 있고 부분합이 M이 되는 경우의 수를 구하는 것이다. 반복문으로 이를 풀이할 경우에 시간 초과가 나게 된다. 투 포인터 알고리즘을 이용해서 이를 해결할 수 있다.

 먼저 부분 배열의 앞을 가리키는 start와 부분배열의 뒤를 가리키는 end를 선언하여 두 개의 포인터로 사용한다. 즉, 두 포인터는 첫 번째 원소의 인덱스(0)를 가리키는 것부터 시작한다.

아래는 이 문제의 해결 방법을 정리한 것이다.

1.   시작점(start)과 끝점(end)이 첫 번째 원소의 인덱스를 가리키게 한다.
2.   부분합과 M을 비교하여 아래와 같이 처리한다.  
    1.   부분합과 M이 같다면 count를 1만큼 증가시킨다.
    2.   부분합이 M보다 작다면 end를 1만큼 증가시킨다.
    3.   부분합이 M보다 크다면 start를 1만큼 증가시킨다.
3.   모든 경우의 수를 확인할 때까지 2번을 반복한다.

```
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	
	int arr[10002];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	int count = 0;
	
	int start = 0;
	int end = 0;
	int sum = 0;
	
	while (end <= N) {
		if (sum < M) {
			sum += arr[end++];
		} else if (sum > M) {
			sum -= arr[start++];
		} else {
			count++;
			sum += arr[end++];
		}
	}
	
	cout << count;
	
	return 0;
}
```