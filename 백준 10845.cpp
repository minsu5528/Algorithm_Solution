#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	queue<int> Q;

	while (n--) {
		string command;
		cin >> command;
		if (command == "push") {
			int num;
			cin >> num;
			Q.push(num);
		}
		else if (command == "pop") {
			if (!Q.empty()) {
				cout << Q.front() << "\n";
				Q.pop();
			}
			else cout << "-1\n";
		}
		else if (command == "size") {
			cout << Q.size() << "\n";
		}
		else if (command == "empty") {
			if (Q.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (command == "front") {
			if (!Q.empty()) cout << Q.front() << "\n";
			else cout << "-1\n";
		}
		else if (command == "back") {
			if (!Q.empty()) cout << Q.back() << "\n";
			else cout << "-1\n";
		}
		else break;
	}
}