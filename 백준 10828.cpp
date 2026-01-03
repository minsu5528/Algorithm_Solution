#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	stack<int> X;

	while (n--) {
		string command;
		int p;

		cin >> command;
		if (command == "push") {
			cin >> p;
			X.push(p);
		}
		else if (command == "pop") {
			if (!X.empty()) {
				cout << X.top() << "\n";
				X.pop();
			}
			else cout << "-1\n";
		}
		else if (command == "size")
			cout << X.size() << "\n";
		else if (command == "empty") {
			if (X.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (command == "top") {
			if (!X.empty()) cout << X.top() << "\n";
			else cout << "-1\n";
		}
	}
}