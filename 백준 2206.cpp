#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[1002][1002];
int vis[1002][1002][2];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int n, m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < m; j++)
			board[i][j] = row[j] - '0';
	}


	memset(vis, -1, sizeof(vis));

	queue<tuple<int, int, int>> Q;
	Q.push({ 0,0,0 });
	vis[0][0][0] = 1;

	while (!Q.empty()) {
		int x, y, broken;
		tie(x, y, broken) = Q.front(); Q.pop();
		if (x == n - 1 && y == m - 1) {
			cout << vis[x][y][broken];
			return 0;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 0 && vis[nx][ny][broken] == -1) {
				vis[nx][ny][broken] = vis[x][y][broken] + 1;
				Q.push({ nx, ny, broken });
			}
			else if (board[nx][ny] == 1 && broken == 0 && vis[nx][ny][1] == -1) {
				vis[nx][ny][1] = vis[x][y][broken] + 1;
				Q.push({ nx, ny, 1 });
			}
		}
	}
	cout << "-1";
	return 0;
}