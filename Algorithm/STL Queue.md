### **들어가며**

 큐는 먼저 들어간 원소가 먼저 나오게 되는 구조여서 FIFO(First In First Out) 자료구조라고 부른다. 그리고 C++ STL에 큐가 구현되어 있어 쉽게 이용할 수 있다! 큐는 BFS, Flood Fill 알고리즘에 보통 사용한다.

### **큐(Queue) 란?**

> **큐(queue)**는 컴퓨터의 기본적인 자료 구조의 한가지로, 먼저 집어 넣은 데이터가 먼저 나오는 FIFO(First In First Out)구조로 저장하는 형식을 말한다. 영어 단어 queue는 표를 사러 일렬로 늘어선 사람들로 이루어진 줄을 말하기도 하며, 먼저 줄을 선 사람이 먼저 나갈 수 있는 상황을 연상하면 된다.  
> 나중에 집어 넣은 데이터가 먼저 나오는 스택과는 반대되는 개념이다.  
> 프린터의 출력 처리나 윈도 시스템의 메시지 처리기, 프로세스 관리 등 **데이터가 입력된 시간 순서대로 처리해야 할 필요가 있는 상황에 이용**된다.  
>   
> \- [위키백과](https://ko.wikipedia.org/wiki/%ED%81%90_(%EC%9E%90%EB%A3%8C_%EA%B5%AC%EC%A1%B0))

### **큐**

 큐에 대해서 아래의 사진을 보고 이해해보자.

[##_Image|kage@bIwKdo/btrq1gJC6Fs/0lBF5w5lqZKM2JY0JdApGk/img.png|CDM|1.3|{"originWidth":542,"originHeight":509,"style":"alignCenter","filename":"1.PNG"}_##]

 위 사진을 보면 원소 32를 넣어서 큐 안에 원소가 5, 17, 32가 들어있게 되었다. 여기서 원소를 제거하면 가장 먼저 들어와있는 원소인 5가 빠져나간다. 이러한 구조를 **큐**라고 부른다.

#### **큐의 성질**

1.   원소를 추가하거나 원소를 제거하기 위해 O(1)의 시간 복잡도가 필요하다.
2.   제일 상단의 원소와 제일 하단의 원소를 확인하기 위해 O(1)의 시간 복잡도가 필요하다.
3.   제일 상단에 있는 원소와 제일 하단에 있는 원소를 제외한 나머지 원소들을 확인하거나 변경하는 것은 원칙적으로 불가능하다. (배열을 이용해 큐를 구현하면 확인하거나 변경가능하도록 만들 수 있다.)

### **STL Queue**

 아래는 queue 헤더 파일의 선언이다.

```
#include <queue>
...
```

#### **Queue 선언**

```
#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	
	queue<int> Q; // 비어있는 int queue 선언
	
	return 0;
}
```

#### **Queue 값 추가**

 queue에 값을 추가하기 위해서는 push() 함수를 사용한다.

```
#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	
	queue<int> Q; // 비어있는 int queue 선언
	
	Q.push(1); // 1
	Q.push(2); // 1 2
	Q.push(3); // 1 2 3
	
	return 0;
}
```

#### **Queue 크기**

 queue의 크기를 구하기 위해서는 size() 함수를 사용한다. 그리고 queue가 비어있는지 확인하기 위해 empty() 함수를 사용한다.

```
#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	
	queue<int> Q; // 비어있는 int queue 선언
	
	Q.push(1); // 1
	Q.push(2); // 1 2
	Q.push(3); // 1 2 3
	
	cout << Q.size() << '\n'; // 3
	
	if (!Q.empty()) {
		cout << "queue is not empty!" << '\n';
	}
	
	return 0;
}
```

#### **Queue 값 삭제**

 queue에 값을 삭제하기 위해서 pop() 함수를 사용한다. 그리고 **큐가 비어있는 데 pop() 함수를 호출하면 런타임 에러가 발생한다!**

```
#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	
	queue<int> Q; // 비어있는 int queue 선언
	
	Q.push(1); // 1
	Q.push(2); // 1 2
	Q.push(3); // 1 2 3
	
	cout << Q.size() << '\n'; // 3
	
	if (!Q.empty()) {
		cout << "queue is not empty!" << '\n';
	}
	
	Q.pop(); // 2 3
	
	return 0;
}
```

#### **Queue 값 확인**

 STL Queue에서는 제일 상단의 원소와 제일 하단의 원소 이외의 원소의 값을 확인하거나 변경할 수 없다. 큐의 제일 상단 원소의 값을 확인하기 위해 front() 함수를 사용하고, 큐의 제일 하단 원소의 값을 확인하기 위해 back() 함수를 사용한다. 그리고 **큐가 비어있는 데 front() 함수나 back() 함수를 호출하면 런타임 에러가 발생한다!**

```
#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	
	queue<int> Q; // 비어있는 int queue 선언
	
	Q.push(1); // 1
	Q.push(2); // 1 2
	Q.push(3); // 1 2 3
	
	cout << Q.size() << '\n'; // 3
	
	if (!Q.empty()) {
		cout << "queue is not empty!" << '\n';
	}
	
	Q.pop(); // 2 3
	
	cout << Q.front() << '\n'; // 2
	cout << Q.back() << '\n'; // 3
	
	return 0;
}
```