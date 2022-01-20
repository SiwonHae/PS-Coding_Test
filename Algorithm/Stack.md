### **들어가며**

 이번에는 스택을 활용하여 수식의 괄호 쌍을 검사하는 알고리즘에 대해 알아보자!

### **수식의 괄호 쌍 예시**

-   ( { { ) } } -> 올바르지 않은 식
-   ( ( ) ) -> 올바른 식

### **수식의 괄호 쌍 해결 알고리즘**

1.   여는 괄호가 나오면 스택에 추가한다.
2.   닫는 괄호가 나왔을 때 아래의 3가지 방법으로 처리한다.
    1.   스택이 비어있으면 올바르지 않은 괄호 쌍이다.
    2.   스택의 top과 짝이 맞지 않는 괄호라면 올바르지 않은 괄호 쌍이다.
    3.   스택의 top과 짝이 맞는 괄호라면 pop한다.
3.   위의 과정을 끝낸 후 스택에 괄호가 남아있으면 올바르지 않은 괄호 쌍이고, 반대로 스택에 괄호가 남아있지 않다면 올바른 괄호 쌍이다.

### **문제 해결**

 아래는 백준(BOJ) 4949번 균형잡힌 세상을 위의 알고리즘을 이용해 해결한 코드이다.

> [https://www.acmicpc.net/problem/4949](https://www.acmicpc.net/problem/4949)

```
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (true) {
		string str;
		getline(cin, str);
		
		if (str == ".") {
			break;
		}
		
		stack<char> S;
		bool isValid = true;
		
		for (auto c : str) {
			if (c == '(' || c == '[') {
				S.push(c);
			} else if (c == ')') {
				if (S.empty() || S.top() != '(') { // 올바르지 않은 괄호 쌍
					isValid = false;
					break;
				}
				S.pop();
			} else if (c == ']') {
				if (S.empty() || S.top() != '[') { // 올바르지 않은 괄호 쌍
					isValid = false;
					break;
				}
				S.pop();
			}
		}
		
		if (!S.empty()) { // 모든 과정을 끝낸 후 스택에 괄호가 남아있으면 올바르지 않음!
			isValid = false;
		}
		
		if (isValid) {
			cout << "yes" << '\n';
		} else {
			cout << "no" << '\n';
		}
	}
	
	return 0;
}
```