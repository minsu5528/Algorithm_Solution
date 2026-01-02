#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N[10] = { 0 };
	string num;

	cin >> num;

	for (auto e : num) {
		if (e == '6' || e == '9') N[6]++;
		else N[e - '0']++;
	}
	if (N[6] % 2 == 0) N[6] = N[6] / 2;
	else N[6] = N[6] / 2 + 1;

	int max = N[0];
	for (int i = 0; i < 9; i++) {
		if (max < N[i]) max = N[i];
	}

	cout << max;
}