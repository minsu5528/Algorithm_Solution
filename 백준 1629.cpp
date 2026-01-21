#include <bits/stdc++.h>
using namespace std;

long long a, b, c;

long long func(long long a, long long b, long long c) {
	if (b == 1) return a % c;
	long long temp = func(a, b / 2, c);
	temp = temp * temp % c;
	if (b % 2 == 0) return temp;
	return temp * a % c;
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c;
	cout << func(a, b, c);
	return 0;
}