#include <bits/stdc++.h>
using namespace std;

int board[100002] = { 0 };

int n, k;
int dx[3] = { -1, 1,2 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	queue<int> Q;
	Q.push(n);

	while (Q.front() != k) {
		int cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 3; dir++) {
			int nx;
			if (dir < 2) nx = cur + dx[dir];
			else nx = cur * dx[dir];
			if (nx < 0 || nx>100000) continue;
			if (board[nx] > 0) continue;
			board[nx] = board[cur] + 1;
			Q.push(nx);
		}
	}

	cout << board[Q.front()];
}