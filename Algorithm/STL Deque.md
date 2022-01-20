### **들어가며**

 **덱(Deque)**은 Double Ended Queue의 약자로 큐에 양쪽 끝에서 원소를 추가하거나 삭제를 할 수 있는 자료구조이다. 그리고 C++ STL에 덱이 구현되어 있어 쉽게 이용할 수 있다!

### **덱(Deque) 이란?**

> **덱**(deque, "deck"과 발음이 같음 ← double-ended queue)은 양쪽 끝에서 삽입과 삭제가 모두 가능한 자료 구조의 한 형태이다.  
> 두 개의 포인터를 사용하여, 양쪽에서 삭제와 삽입을 발생시킬 수 있다. 큐와 스택을 합친 형태로 생각할 수 있다.  
>   
> \- [위키백과](https://ko.wikipedia.org/wiki/%EB%8D%B1_(%EC%9E%90%EB%A3%8C_%EA%B5%AC%EC%A1%B0))

### **덱**

 덱에 대해서 아래의 사진을 보고 이해해보자.

[##_Image|kage@brEqYk/btrq22sx6My/ifFf4Mk85kEB4IhLyrJeo1/img.png|CDM|1.3|{"originWidth":855,"originHeight":556,"style":"alignCenter","filename":"1.PNG"}_##]

 위 사진을 보면 원소 32를 back에 넣어서 덱 안에 원소가 5, 17, 32가 들어있게 된다. 여기서 front에 있는 원소 5를 제거하면 덱 안에 17, 32가 남게 된다. 그리고 원소 54를 front에 넣어서 54, 17, 32가 된다. 그리고 back에 있는 원소 32를 제거하면 덱 안에 54, 17이 남게 된다.

#### **덱의 성질**

1.   원소를 추가하거나 원소를 제거하기 위해서 O(1)의 시간 복잡도가 필요하다.
2.   제일 상단의 원소와 제일 하단의 원소를 확인하기 위해서 O(1)의 시간 복잡도가 필요하다.
3.   제일 상단에 있는 원소와 제일 하단에 있는 원소를 제외한 나머지 원소들을 확인하거나 변경하는 것은 원칙적으로 불가능하다. **(하지만, STL Deque에서는 인덱스로 원소에 접근할 수 있다. STL Stack과 STL Queue에서는 불가능하다!)**

### **STL Deque**

 아래는 deque 헤더 파일의 선언이다.

```
#include <deque>
...
```

#### **Deque 선언**

```
#include <iostream>
#include <deque>
using namespace std;

int main(void) {
	
	deque<int> DQ; // 비어있는 int deque 선언
	
	return 0;
}
```

#### **Deque 값 추가**

 deque에 값을 추가하기 위해서 두 가지 방법을 사용할 수 있다. 덱의 제일 앞에 값을 추가하기 위해서 push\_front() 함수를 사용하고, 덱의 제일 뒤에 값을 추가하기 위해서 push\_back() 함수를 사용한다. 그리고 insert() 함수를 이용해 특정 위치에 값을 추가할 수도 있다.

```
#include <iostream>
#include <deque>
using namespace std;

int main(void) {
	
	deque<int> DQ; // 비어있는 int deque 선언
	
	DQ.push_front(1); // 1
	DQ.push_back(2); // 1 2
	DQ.push_front(3); // 3 1 2
	
	DQ.insert(DQ.begin() + 1, 5); // 3 5 1 2
	
	return 0;
}
```

#### **Deque 크기**

 deque의 크기를 구하기 위해서는 size() 함수를 사용한다. 그리고 deque가 비어있는지 확인하기 위해 empty() 함수를 사용한다.

```
#include <iostream>
#include <deque>
using namespace std;

int main(void) {
	
	deque<int> DQ; // 비어있는 int deque 선언
	
	DQ.push_front(1); // 1
	DQ.push_back(2); // 1 2
	DQ.push_front(3); // 3 1 2
	
	DQ.insert(DQ.begin() + 1, 5); // 3 5 1 2
	
	cout << DQ.size() << '\n'; // 4
	
	if (!DQ.empty()) {
		cout << "deque is not empty!" << '\n';
	}
	
	return 0;
}
```

#### **Deque 값 삭제**

 deque에 값을 삭제하기 위해서 두 가지 방법을 사용할 수 있다. 덱의 제일 앞에 있는 값을 삭제하기 위해서 pop\_front() 함수를 사용하고, 덱의 제일 뒤에 있는 값을 삭제하기 위해서 pop\_back() 함수를 사용한다. 그리고 erase() 함수를 이용해 특정 위치의 값을 삭제할 수 있고 clear() 함수를 이용해 덱에 있는 모든 원소들을 삭제할 수 있다.

```
#include <iostream>
#include <deque>
using namespace std;

int main(void) {
	
	deque<int> DQ; // 비어있는 int deque 선언
	
	DQ.push_front(1); // 1
	DQ.push_back(2); // 1 2
	DQ.push_front(3); // 3 1 2
	
	DQ.insert(DQ.begin() + 1, 5); // 3 5 1 2
	
	cout << DQ.size() << '\n'; // 4
	
	if (!DQ.empty()) {
		cout << "deque is not empty!" << '\n';
	}
	
	DQ.pop_front(); // 5 1 2
	DQ.pop_back(); // 5 1
	
	DQ.erase(DQ.begin() + 1); // 5
    
	DQ.clear(); // { }
	
	return 0;
}
```

#### **Deque 값 확인**

 deque의 제일 앞에 있는 원소의 값을 확인하기 위해서 front() 함수를 사용하고, deque의 제일 뒤에 있는 원소의 값을 확인하기 위해서 back() 함수를 사용한다. 그리고 인덱스를 이용해 원소의 값을 확인할 수 있다.

```
#include <iostream>
#include <deque>
using namespace std;

int main(void) {
	
	deque<int> DQ; // 비어있는 int deque 선언
	
	DQ.push_front(1); // 1
	DQ.push_back(2); // 1 2
	DQ.push_front(3); // 3 1 2
	
	DQ.insert(DQ.begin() + 1, 5); // 3 5 1 2
	
	cout << DQ.size() << '\n'; // 4
	
	if (!DQ.empty()) {
		cout << "deque is not empty!" << '\n';
	}
    
	cout << DQ.front() << '\n'; // 3
	cout << DQ.back() << '\n'; // 2
	cout << DQ[1] << '\n'; // 5
    
	return 0;
}
```