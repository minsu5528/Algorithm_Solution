#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[1002];
int disp1[1002][1002]; // 상근이
int disp2[1002][1002]; // 불

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int t, n, m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;

	while (t--) {
		cin >> m >> n;

		queue<pair<int, int>> Q1; // 상근이
		queue<pair<int, int>> Q2; // 불

		for (int i = 0; i < n; i++) fill(disp1[i], disp1[i] + m, -1);
		for (int i = 0; i < n; i++) fill(disp2[i], disp2[i] + m, -1);

		for (int i = 0; i < n; i++) cin >> board[i];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == '@') {
					Q1.push({ i,j });
					disp1[i][j] = 0;
				}
				if (board[i][j] == '*') {
					Q2.push({ i,j });
					disp2[i][j] = 0;
				}
			}
		}

		while (!Q2.empty()) {
			auto cur = Q2.front(); Q2.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (board[nx][ny] == '#' || disp2[nx][ny] >= 0) continue;
				disp2[nx][ny] = disp2[cur.X][cur.Y] + 1;
				Q2.push({ nx,ny });
			}
		}

		bool flag = false;
		while (!Q1.empty()) {
			auto cur = Q1.front(); Q1.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
					cout << disp1[cur.X][cur.Y] + 1 << "\n";
					flag = true;
					break;
				}
				if (board[nx][ny] == '#' || disp1[nx][ny] >= 0) continue;
				if (disp2[nx][ny] != -1 && disp1[cur.X][cur.Y] + 1 >= disp2[nx][ny]) continue;
				disp1[nx][ny] = disp1[cur.X][cur.Y] + 1;
				Q1.push({ nx,ny });
			}
			if (flag) break;
		}

		if (!flag) cout << "IMPOSSIBLE\n";
	}
	return 0;
}