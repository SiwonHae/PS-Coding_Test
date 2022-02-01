#include <bits/stdc++.h>
using namespace std;

using ll = long long;

/*
B가 10이라고 가정하면
A^10 => (A^5)^2 => ((A^2)^2*A)^2 => (((A)^2)^2*A)^2
B가 더이상 안나눠질 때까지 2로 나눠서 1부터 시작하게함
*/

ll POW(ll a, ll b, ll c) {
	if (b == 0) { // base condition
		return 1;
	}
	
	ll val = POW(a, b / 2, c);
	val = val * val % c;
	
	// b가 짝수, 홀수를 나눠서 처리함
	if (b % 2 == 0) {
		return val;
	} else {
		return val * a % c;
	}
	
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll a, b, c;
	cin >> a >> b >> c;
	cout << POW(a, b, c);
	
	return 0;
}
