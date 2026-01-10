#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		deque<int> DQ;

		string p;
		cin >> p;

		int n;
		cin >> n;

		string x;
		cin >> x;

		string temp = "";

		for (int i = 0; i < x.length(); i++) {
			if (isdigit(x[i])) {
				temp += x[i];
			}
			else {
				if (!temp.empty()) {
					DQ.push_back(stoi(temp));
					temp = "";
				}
			}
		}

		int error = 1;
		int R_count = 0;
		for (auto k : p) {
			if (k == 'R') R_count++;

			if (k == 'D') {
				if (DQ.empty()) {
					error = -1;
					break;
				}
				if (R_count % 2 == 0) {
					DQ.pop_front(); n--;
				}
				else {
					DQ.pop_back();
					n--;
				}
			}
		}

		if (error == -1) cout << "error\n";
		else {
			cout << "[";
			if (R_count % 2 == 0) {
				for (int i = 0; i < DQ.size(); i++) {
					cout << DQ[i];
					if (i != DQ.size() - 1) cout << ",";
				}
			}
			else {
				for (int i = DQ.size() - 1; i >= 0; i--) {
					cout << DQ[i];
					if (i != 0) cout << ",";
				}
			}
			cout << "]\n";
		}

	}
}