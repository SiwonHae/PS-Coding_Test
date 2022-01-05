### **들어가며**

 **STL**은 C++에서 제공되는 라이브러리이다. STL에는 다양한 알고리즘과 자료구조가 구현되어 있다. 따라서 직접, 힘들게 우리가 구현하지 않고 사용할 수 있어서 코드 작성에 큰 도움을 준다.

### **STL 이란?**

> **표준 템플릿 라이브러리(STL: Standard Template Library)**는 **C++**을 위한 **라이브러리**로서 **C++ 표준 라이브러리**의 많은 부분에 영향을 끼쳤다. 이것은 알고리즘, 컨테이너, 함수자 그리고 반복자라고 불리는 네 가지의 구성 요소를 제공한다.  
>   
> \- [위키백과](https://ko.wikipedia.org/wiki/%ED%91%9C%EC%A4%80_%ED%85%9C%ED%94%8C%EB%A6%BF_%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC)

### **STL Vector**

 Vector는 배열과 비슷한 기능을 한다. C++에서는 배열을 선언할 때 크기를 명시해야 하고, 무조건 해당 크기 안에서만 사용해야 한다. 하지만, vector는 동적으로 원소를 추가할 수 있고 크기가 늘어나거나 줄어들 수 있는 일종의 가변배열이다. 그리고 **STL을 함수 인자로 넘길 때 복사본을 만들어서 보내기 때문에 원본 값에 영향을 주지 않는다.**

 아래는 vector 헤더 파일을 선언하는 방법이다.

```
#include <vector>
...
```

 vector의 구조는 다음과 같다.

1.   begin: 첫 번째 위치
2.   front: 첫 번째 원소
3.   back: 마지막 원소
4.   end: 마지막 + 1 위치
5.   size: 원소들의 개수
6.   capacity: 원소들을 담을 수 있는 메모리가 할당되어 있는 공간의 크기

[##_Image|kage@FIIX6/btrpQYj1TR2/GhfxIFN1NAHaGIaa7tvqFK/img.png|CDM|1.3|{"originWidth":906,"originHeight":243,"style":"alignCenter","filename":"2.PNG"}_##]

#### **Vector 선언**

```
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	vector<int> v1(4, 3); // int vector 생성 후 4개의 원소를 3으로 초기화! { 3, 3, 3, 3 }
	vector<int> v2(3); // int vector 생성 후 3개의 원소를 0으로 초기화! { 0, 0, 0 }
    vector<int> v3 = { 1, 2, 3, 4, 5 }; // int vector 생성 후 1, 2, 3, 4, 5로 초기화!
    vector<int> v4; // int vector 생성! { }
    vector<int> v5(v4); // vector v4를 복사하여 vector v5 생성! { }
}
```

#### **Vector 크기**

 vector의 크기를 구하는 방법은 2가지가 있다.

1.   vector의 원소들의 개수 구하기. => size
2.   vector의 원소들을 담을 수 있는 메모리가 할당되어 있는 공간의 크기 구하기. => capacity

[##_Image|kage@5Lkec/btrpPEM7mnV/eRYHLRuoIxDNDRk3eynZZ1/img.png|CDM|1.3|{"originWidth":885,"originHeight":221,"style":"alignCenter","filename":"1.PNG"}_##]

```
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	vector<int> v1(4, 3); // int vector 생성 후 4개의 원소를 3으로 초기화! { 3, 3, 3, 3 }
	cout << v1.size() << '\n'; // 4
}
```

#### **Vector 값 추가**

 vector의 값을 추가하는 방법은 2가지가 있다.

1.   vector에 시작(맨 앞)에 값을 추가하기. => insert
2.   vector의 끝(마지막 위치)에 값을 추가하기. => push\_back

```
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	vector<int> v1(4, 3); // int vector 생성 후 4개의 원소를 3으로 초기화! { 3, 3, 3, 3 }
	v1.insert(v1.begin(), 1); // { 1, 3, 3, 3, 3 }
	v1.push_back(5); // { 1, 3, 3, 3, 3, 5 }
}
```

#### **Vector 값 삭제**

 vector의 값을 삭제하는 방법은 3가지가 있다.

1.   vector의 마지막에 있는 값 제거하기. => pop\_back
2.   vector의 특정 위치(index)에 있는 값 제거하기. => erase
3.   vector의 모든 값을 제거하기. => clear

```
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	vector<int> v1(4, 3); // int vector 생성 후 4개의 원소를 3으로 초기화! { 3, 3, 3, 3 }
	v1.insert(v1.begin(), 1); // { 1, 3, 3, 3, 3 }
	v1.push_back(5); // { 1, 3, 3, 3, 3, 5 }
	v1.pop_back(); // { 1, 3, 3, 3, 3 }
	v1.erase(v1.begin()); // { 3, 3, 3, 3 }
	v1.clear(); // { }
}
```

#### **Vector 값 출력**

 vector의 값을 출력하는 방법 중 2가지를 소개한다.

1.   Range-based for loop을 이용하여 출력하기. => C++11 부터 사용 가능
2.   for loop을 이용하여 출력하기.

```
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	vector<int> v = { 1, 2, 3, 4, 5};
	
	// 1. Range-based for loop
	for (int i : v) {
		cout << i << ' ';
	}
	// 1 2 3 4 5
	cout << '\n';
	
	// 2. for loop
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	// 1 2 3 4 5
	cout << '\n';
}
```