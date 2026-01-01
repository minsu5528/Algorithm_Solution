#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int a[100000] = { 0 };
	int check[2000000] = { 0 };

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		check[a[i]] = 1;
	}

	int x;
	cin >> x;

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (check[x - a[i]] == 1) count++;
	}

	cout << count / 2;
}