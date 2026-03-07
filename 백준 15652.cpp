#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void func(int cur) {
	if (cur == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	int st;
	if (cur == 0) st = 1;
	else st = arr[cur - 1];

	for (int i = st; i <= n; i++) {
		arr[cur] = i;
		func(cur + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(0);
}