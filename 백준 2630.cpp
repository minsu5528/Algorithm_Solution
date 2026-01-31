#include <bits/stdc++.h>
using namespace std;

int board[150][150];
int N;
int cnt[2];

bool check(int x, int y, int n) {
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (board[x][y] != board[i][j]) return false;
	return true;
}

void solve(int x, int y, int n) {
	if (check(x, y, n)) {
		cnt[board[x][y]] += 1;
		return;
	}
	int k = n / 2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			solve(x + i * k, y + j * k, k);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	solve(0, 0, N);
	for (int i = 0; i < 2; i++) cout << cnt[i] << "\n";
}