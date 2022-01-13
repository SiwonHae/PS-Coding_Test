### **들어가며**

 **연결 리스트(Linked List)**는 3가지 종류가 있다. 단일 연결 리스트(Singly Linked List), 이중 연결 리스트(Doubly Linked List), 원형 연결 리스트(Circular Linked List)가 이에 해당한다. 그리고 **C++ STL**에 연결 리스트가 구현되어 있어 손쉽게 사용할 수 있다!

### **연결 리스트(Linked List)란?**

> **연결 리스트, 링크드 리스트(linked list)**는 각 노드가 데이터와 포인터를 가지고 한 줄로 연결되어 있는 방식으로 데이터를 저장하는 **자료 구조**이다. 이름에서 말하듯이 데이터를 담고 있는 노드들이 연결되어 있는데, 노드의 포인터가 다음이나 이전의 노드와의 연결을 담당하게 된다.  
> 연결 리스트의 종류로는 단일 연결 리스트, 이중 연결 리스트 등이 있다.  
> 연결 리스트는 늘어선 노드의 중간지점에서도 자료의 추가와 삭제가 O(1)의 시간에 가능하다는 장점을 갖는다. 그러나 배열이나 트리 구조와는 달리 특정 위치의 데이터를 검색해 내는데에는 O(n)의 시간이 걸리는 단점도 갖고 있다.  
>   
> \- [위키백과](https://ko.wikipedia.org/wiki/%EC%97%B0%EA%B2%B0_%EB%A6%AC%EC%8A%A4%ED%8A%B8)

### **연결 리스트**

 연결리스트를 아래의 예시 사진을 보고 이해해보자.

[##_Image|kage@bQq7kM/btrp7kgdPe2/NmdwzXskpoGnf483PnI2u1/img.png|CDM|1.3|{"originWidth":623,"originHeight":129,"style":"alignCenter","caption":"단일 연결 리스트(Singly Linked List)","filename":"1.PNG"}_##]

 위 사진은 단일 연결 리스트를 표현 한 것이다. 만약 3번째 원소인 62를 찾고 싶으면 5를 지나서 17을 가고, 17을 거쳐서 62를 가야한다. 5는 자기 다음 차례가 17이라는 것만을 알고 있고, 17은 자기 다음 차례가 62라는 것만을 알고 있다는 것이다! 따라서 5만 알고 있으면 17, 62, 2를 알아 낼 수 있다.

#### **연결 리스트 성질**

1.   n번째 원소를 확인하거나 변경하기 위해서 O(n)의 시간 복잡도가 필요하다.
2.   임의의 위치에 원소를 추가하거나 임의의 위치에 있는 원소를 제거하기 위해서 O(1)의 시간 복잡도가 필요하다.

#### **연결 리스트 종류**

[##_Image|kage@6bpQU/btrp7Rx023Y/K4AkXs4ps1DiM18zkZcZ8k/img.png|CDM|1.3|{"originWidth":630,"originHeight":363,"style":"alignCenter","caption":"차례로 단일 연결 리스트, 이중 연결 리스트, 원형 연결 리스트","filename":"2.PNG"}_##]

 제일 위에 있는 리스트는 단일 연결 리스트다. 단일 연결 리스트는 각각의 원소가 자신의 다음 원소의 주소를 들고 있다.

 두 번째 리스트는 이중 연결 리스트다. 이중 연결 리스트는 각각의 원소가 자신의 이전 원소와 자신의 다음 원소의 주소를 모두 들고 있다. STL에 있는 연결리스트는 바로 이것인 이중 연결 리스트다.

 세 번째 리스트는 원형 연결 리스트다. 원형 연결 리스트는 끝 원소와 처음 원소가 연결되어 있다.

#### **배열과 연결 리스트의 차이**

|   | 배열 | 연결 리스트 |
| --- | --- | --- |
| n번째 원소 접근 | O(1) | O(n) |
| 임의의 위치에 원소 추가 or 제거 | O(n) | O(1)   단, 추가 or 제거하고 싶은 위치의 주소를 알고 있을 경우! |
| 메모리 상의 배치 | 연속 | 불연속 |

 배열과 연결 리스트는 메모리 상에 원소를 놓는 방법은 달라도 원소들 사이의 선 후 관계가 일대일로 정의 된다. 그래서 배열과 연결 리스트는 선형 자료구조라고 불린다.

### **STL List**

 아래는 list 헤더 파일을 선언하는 방법이다.

```
#include <list>
...
```

#### **List 선언**

```
#include <iostream>
#include <list>
using namespace std;

int main(void) {
	list<int> li1; // 비어있는 int list 생성!
    list<char> li2; // 비어있는 char list 생성!
    
    list<int> li3(5); // int list 생성 후 5개의 원소를 0으로 초기화!
    list<int> li4(4, 3) // int list 생성 후 4개의 원소를 3으로 초기화! { 3, 3, 3, 3 }
    
	list<int> L = { 3, 7 }; // int list 생성 후 3, 7로 초기화!
	
	return 0;
}
```

#### **List 값 추가**

 List에 값을 추가하는 방법은 2가지가 있다.

1.   list의 시작(맨 앞)에 값을 추가하기. => push\_front()
2.   list의 끝(마지막 위치)에 값을 추가하기. => push\_back()
3.   list의 iterator가 가리키는 위치 앞에 값을 추가하기. => insert(iterator, element)

```
#include <iostream>
#include <list>
using namespace std;

int main(void) {
	list<int> L = { 3, 7 }; // int list 생성 후 3, 7로 초기화!
	list<int>::iterator cur = L.begin(); // cur는 3을 가리키고 있다!
	L.push_front(1); // { 1, 3, 7 }
	L.push_back(10); // { 1, 3, 7, 10 }
	L.insert(cur, 5); // cur가 가리키는 곳 앞에 5를 추가! { 1, 5, 3, 7, 10 }
	cur++; // cur가 1칸 앞을 가리킨다! cur는 7을 가리킨다!
    
	return 0;
}
```

#### **List 값 삭제**

 List의 값을 삭제하는 방법은 3가지가 있다.

1.   list의 시작(맨 앞)에 있는 값을 삭제하기. => pop\_front()
2.   list의 끝(마지막 위치)에 있는 값을 삭제하기. => pop\_back()
3.   list의 iterator가 가리키는 위치에 있는 값을 삭제하기. => erase(iterator)

```
#include <iostream>
#include <list>
using namespace std;

int main(void) {
	list<int> L = { 3, 7 }; // int list 생성 후 3, 7로 초기화!
	list<int>::iterator cur = L.begin(); // cur는 3을 가리키고 있다!
	L.push_front(1); // { 1, 3, 7 }
	L.push_back(10); // { 1, 3, 7, 10 }
	L.insert(cur, 5); // cur가 가리키는 곳 앞에 5를 추가! { 1, 5, 3, 7, 10 }
	cur++; // cur가 1칸 앞을 가리킨다! cur는 7을 가리킨다!
    
    L.pop_front(); // { 5, 3, 7, 10 }
    L.pop_back(); // { 5, 3, 7 }
    L.erase(cur); // { 5, 3 }
    
    for (auto i : L) {
    	cout << i << ' ';
    }
    
	return 0;
}
```