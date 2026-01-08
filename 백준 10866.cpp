#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	deque <int> DQ;

	while (n--) {
		string command;
		cin >> command;

		if (command == "push_front") {
			int x;
			cin >> x;
			DQ.push_front(x);
		}
		else if (command == "push_back") {
			int x;
			cin >> x;
			DQ.push_back(x);
		}
		else if (command == "pop_front") {
			if (!DQ.empty()) {
				cout << DQ.front() << "\n";
				DQ.pop_front();
			}
			else cout << "-1\n";
		}
		else if (command == "pop_back") {
			if (!DQ.empty()) {
				cout << DQ.back() << "\n";
				DQ.pop_back();
			}
			else cout << "-1\n";
		}
		else if (command == "size") {
			cout << DQ.size() << "\n";
		}
		else if (command == "empty") {
			if (DQ.empty())
				cout << "1\n";
			else cout << "0\n";
		}
		else if (command == "front") {
			if (!DQ.empty()) {
				cout << DQ.front() << "\n";
			}
			else cout << "-1\n";
		}
		else if (command == "back") {
			if (!DQ.empty()) {
				cout << DQ.back() << "\n";
			}
			else cout << "-1\n";
		}
	}
}