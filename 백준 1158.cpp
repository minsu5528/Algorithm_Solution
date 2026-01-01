#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	list<int> N;

	for (int i = 1; i <= n; i++) {
		N.push_back(i);
	}
	auto curcor = N.begin();

	cout << '<';
	while (n--) {
		for (int i = 0; i < k - 1; i++) {
			curcor++;
			if (curcor == N.end()) curcor = N.begin();
		}
		cout << *curcor;

		if (N.size() > 1) cout << ", ";
		curcor = N.erase(curcor);

		if (curcor == N.end()) curcor = N.begin();
	}
	cout << '>';

}