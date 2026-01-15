#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502] = { 0 };
bool vis[502][502];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int count = 0;
	int area = 0;
	queue <pair<int, int>> Q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] && board[i][j]) {
				int temp = 0;
				vis[i][j] = 1;
				Q.push({ i, j });
				count++;
				while (!Q.empty()) {
					temp++;
					pair<int, int> cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny <0 || ny >m) continue;
						if (vis[nx][ny] || board[nx][ny] != 1) continue;
						vis[nx][ny] = 1;
						Q.push({ nx,ny });
					}
				}
				if (area < temp) area = temp;
			}
		}
	}

	cout << count << "\n" << area;
}