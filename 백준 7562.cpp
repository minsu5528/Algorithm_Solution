#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[302][302];

int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };

int t, l;

int main(void) {
	cin >> t;

	while (t--) {
		cin >> l;
		int ax, ay;
		cin >> ax >> ay;
		int bx, by;
		cin >> bx >> by;

		for (int i = 0; i < l; i++) fill(board[i], board[i] + l, -1);

		queue<pair<int, int>> Q;
		Q.push({ ax,ay });
		board[ax][ay] = 0;

		while (!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
				if (board[nx][ny] >= 0) continue;
				Q.push({ nx,ny });
				board[nx][ny] = board[cur.X][cur.Y] + 1;
			}
		}
		cout << board[bx][by] << "\n";
	}
}