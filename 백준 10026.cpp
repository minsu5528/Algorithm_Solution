#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[102];
bool vis[102][102];
bool vis1[102][102];

int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> board[i];

	queue<pair<int, int>> Q;
	int count1 = 0;
	int count2 = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < board[i].length(); j++) {
			if (board[i][j] == 'B') {
				if (vis[i][j] == false) {
					Q.push({ i,j });
					vis[i][j] = 1;
					vis1[i][j] = 1;
					count1++; count2++;
				}

				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= board[i].length() || ny < 0 || ny >= n) continue;
						if (vis[nx][ny] || board[nx][ny] != 'B') continue;
						Q.push({ nx,ny });
						vis[nx][ny] = 1;
						vis1[nx][ny] = 1;
					}
				}
			}

			if (board[i][j] == 'R' || board[i][j] == 'G') {
				if (vis1[i][j] == false) {
					Q.push({ i,j });
					vis1[i][j] = true;
					count2++;
				}

				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= board[i].length() || ny < 0 || ny >= n) continue;
						if (vis1[nx][ny] == true || board[nx][ny] == 'B') continue;
						Q.push({ nx,ny });
						vis1[nx][ny] = true;
					}
				}

				if (board[i][j] == 'R') {
					if (vis[i][j] == false) {
						Q.push({ i,j });
						vis[i][j] = true;
						count1++;
					}

					while (!Q.empty()) {
						auto cur = Q.front(); Q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if (nx < 0 || nx >= board[i].length() || ny < 0 || ny >= n) continue;
							if (vis[nx][ny] == true || board[nx][ny] != 'R') continue;
							Q.push({ nx,ny });
							vis[nx][ny] = true;
						}
					}
				}

				if (board[i][j] == 'G') {
					if (vis[i][j] == false) {
						Q.push({ i,j });
						vis[i][j] = 1;
						count1++;
					}

					while (!Q.empty()) {
						auto cur = Q.front(); Q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if (nx < 0 || nx >= board[i].length() || ny < 0 || ny >= n) continue;
							if (vis[nx][ny] || board[nx][ny] != 'G') continue;
							Q.push({ nx,ny });
							vis[nx][ny] = 1;
						}
					}
				}
			}

		}
	}
	cout << count1 << " " << count2;
}