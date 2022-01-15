### **들어가며**

 앞으로 세 가지 관련 있는 자료구조인 **스택, 큐, 덱**에 대해서 다룰 것이다. 스택은 먼저 들어간 원소가 제일 나중에 나오게 되는 구조여서 **FILO(First In Last Out)** 자료구조라고 부르기도 한다. 또한 반대로 나중에 들어간 원소가 제일 먼저 나오게 되는 구조이므로 **LIFO(Last In First Out)**의 형태를 띠는 자료구조이기도 하다. 그리고 C++ STL에 스택이 구현되어 있어 쉽게 이용할 수 있다!

### **스택(Stack) 이란?**

> **스택(stack)**은 제한적으로 접근할 수 있는 나열 구조이다. 그 접근 방법은 언제나 목록의 끝에서만 일어난다. 끝먼저내기 목록(Pushdown list)이라고도 한다.  
> 스택은 한 쪽 끝에서만 자료를 넣거나 뺄 수 있는 선형 구조(LIFO - Last In First Out)으로 되어 있다. 자료를 넣는 것을 '밀어넣는다' 하여 푸쉬(push)라고 하고 반대로 넣어둔 자료를 꺼내는 것을 팝(pop)이라고 하는데, 이때 꺼내지는 자료는 가장 최근에 푸쉬한 자료부터 나오게 된다. 이처럼 나중에 넣은 값이 먼저 나오는 것을 LIFO 구조라고 한다.  
>   
> \- [위키백과](https://ko.wikipedia.org/wiki/%EC%8A%A4%ED%83%9D)

### **스택**

 스택에 대해서 아래의 사진을 보고 이해해보자.

[##_Image|kage@FhVIm/btrqQfjzEX6/SYvi1ciYABMDtkGl1b1TF1/img.png|CDM|1.3|{"originWidth":637,"originHeight":469,"style":"alignCenter","filename":"1.PNG"}_##]

 위 사진을 보면 32 원소를 넣고, 47 원소를 넣었다. 그리고 원소를 제거할 때 가장 마지막에 넣은 47 원소가 빠져나가는 것을 알 수 있는데 이러한 구조를 **스택**이라고 부른다.

#### **스택의 성질**

1.   원소를 추가하거나 원소를 제거하기 위해 O(1)의 시간 복잡도가 필요하다.
2.   제일 상단의 원소를 확인하기 위해 O(1)의 시간 복잡도가 필요하다.
3.   제일 상단에 있는 원소가 아닌 원소들을 확인하거나 변경하는 것은 원칙적으로 불가능하다. (배열을 이용해 스택을 구현하면 확인 가능하도록 만들 수 있다.)

### **STL Stack**

 아래는 stack 헤더 파일의 선언이다.

```
#include <stack>
...
```

#### **Stack 선언**

```
#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	
	stack<int> S1; // 비어있는 int stack 선언
	stack<char> S2; // 비어있는 char stack 선언
	
	return 0;
}
```

#### **Stack 값 추가**

 stack에 값을 추가하기 위해서는 push() 함수를 사용하면 된다. 

```
#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	
	stack<int> S; // 비어있는 int stack 선언
	
	S.push(1); // 1
	S.push(2); // 1 2
	S.push(3); // 1 2 3
	
	return 0;
}
```

#### **Stack 크기**

 stack의 크기를 구하기 위해서는 size() 함수를 사용하면 된다. 그리고 stack이 비어있는지 확인하기 위해서 empty() 함수를 사용할 수 있다.

```
#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	
	stack<int> S; // 비어있는 int stack 선언
	
	S.push(1); // 1
	S.push(2); // 1 2
	S.push(3); // 1 2 3
	
	cout << S.size() << '\n'; // 3
	
	if (!S.empty()) {
		cout << "stack is not empty!" << '\n';
	}
	
	
	return 0;
}
```

#### **Stack 값 삭제**

 stack에 값을 삭제하기 위해서는 pop() 함수를 사용하면 된다. **스택이 비어있는 데 pop() 함수를 호출하면 런타임 에러가 발생한다!**

```
#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	
	stack<int> S; // 비어있는 int stack 선언
	
	S.push(1); // 1
	S.push(2); // 1 2
	S.push(3); // 1 2 3
	
	cout << S.size() << '\n'; // 3
	
	if (!S.empty()) {
		cout << "stack is not empty!" << '\n';
	}
	
	S.pop(); // 1 2
	
	return 0;
}
```

#### **Stack 제일 상단 값 확인**

 STL Stack에서는 제일 상단 이외의 원소의 값을 확인하거나 변경할 수 없다. 스택의 제일 상단의 값을 확인하기 위해서는 top() 함수를 사용하면 된다. **그리고 스택이 비어있는 데 top() 함수를 호출하면 런타임 에러가 발생한다!**

```
#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	
	stack<int> S; // 비어있는 int stack 선언
	
	S.push(1); // 1
	S.push(2); // 1 2
	S.push(3); // 1 2 3
	
	cout << S.size() << '\n'; // 3
	
	if (!S.empty()) {
		cout << "stack is not empty!" << '\n';
	}
	
	S.pop(); // 1 2
	cout << S.top() << '\n'; // 2
	
	S.pop(); // 1
	cout << S.top() << '\n'; // 1
	
	return 0;
}
```