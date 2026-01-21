#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[52][52];
bool vis[52][52];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	int t;
	cin >> t;


	while (t--) {
		int count = 0;
		int n, m, k;
		cin >> m >> n >> k;

		for (int i = 0; i < n; i++) fill(board[i], board[i] + m, 0);
		for (int i = 0; i < n; i++) fill(vis[i], vis[i] + m, 0);

		queue<pair<int, int>> Q;

		while (k--) {
			int a, b;
			cin >> b >> a;
			board[a][b] = 1;
		}


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 1 && vis[i][j] == 0) {
					Q.push({ i,j });
					vis[i][j] = 1;
					count++;
				}

				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (board[nx][ny] == 0 || vis[nx][ny]) continue;
						Q.push({ nx,ny });
						vis[nx][ny] = 1;
					}
				}
			}
		}
		cout << count << "\n";
	}

	return 0;
}
