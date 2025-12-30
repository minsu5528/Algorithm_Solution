#include <bits/stdc++.h>
using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--) {
		string passward;
		cin >> passward;

		list<char> P = {};
		auto cursor = P.begin();
		for (auto e : passward) {
			if (e == '<') {
				if (cursor != P.begin()) cursor--;
			}
			else if (e == '>') {
				if (cursor != P.end()) cursor++;
			}
			else if (e == '-') {
				if (cursor != P.begin()) {
					cursor--;
					cursor = P.erase(cursor);
				}
			}
			else {
				P.insert(cursor, e);
			}
		}

		for (auto c : P) cout << c;
		cout << "\n";
	}

}