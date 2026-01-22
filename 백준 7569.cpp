#include <bits/stdc++.h>
using namespace std;


int dx[6] = { 1,0,0,-1,0,0 };
int dy[6] = { 0,1,0,0,-1,0 };
int dz[6] = { 0,0,1,0,0,-1 };

int n, m, h;

int board[102][102][102];
int vis[102][102][102] = { 0 };

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >> h;

	queue<tuple<int, int, int>> Q;

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int temp;
				cin >> temp;
				board[i][j][k] = temp;
				if (temp == 1) {
					Q.push({ i,j,k }); vis[i][j][k] = 1;
				}
				else if (temp == -1) vis[i][j][k] = 1;
			}
		}
	}

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nx = get<0>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];
			int nz = get<2>(cur) + dz[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (vis[nx][ny][nz] || board[nx][ny][nz] != 0) continue;
			Q.push({ nx,ny,nz });
			vis[nx][ny][nz] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < h; k++) {
				if (vis[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
				else {
					if (max <= vis[i][j][k]) max = vis[i][j][k];
				}
			}
		}
	}
	if (max == 1) cout << "0";
	else cout << max - 1;
	return 0;
}