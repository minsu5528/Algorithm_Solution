#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

char board[1002][1002];
int disp[1002][1002];
int disp1[1002][1002];

int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	queue<pair<int, int>> Q;

	int check_i = 0, check_j = 0;
	for (int i = 0; i < n; i++) {
		fill(disp[i], disp[i] + m, -1);
		fill(disp1[i], disp1[i] + m, -1);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'F') {
				Q.push({ i,j });
				disp[i][j] = 0;
			}
			if (board[i][j] == 'J') {
				check_i = i; check_j = j;
			}
		}
	}

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == '#' || disp[nx][ny] >= 0) continue;
			disp[nx][ny] = disp[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}

	Q.push({ check_i,check_j });
	disp1[check_i][check_j] = 0;

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				cout << disp1[cur.X][cur.Y] + 1;
				return 0;
			}
			if (board[nx][ny] == '#' || disp1[nx][ny] >= 0) continue;
			if (disp[nx][ny] != -1 && disp1[cur.X][cur.Y] + 1 >= disp[nx][ny]) continue;
			disp1[nx][ny] = disp1[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE";
}