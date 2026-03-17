#include <bits/stdc++.h>
using namespace std;

typedef struct CCTV {
	int cctv_number;
	int x;
	int y;
}cctv;

int n, m;
int board[10][10];
int cctv_cnt, blind_cnt = -1;
int rotation[5] = { 4,2,4,4,1 };
cctv a[8];

void print_board() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << board[i][j] << " ";
		cout << "\n";
	}
}

void left(int x, int y, int flag) {

	if (flag == 0) {
		for (int a = y - 1; a > -1; a--) {
			if (board[x][a] == 6) break;
			if (board[x][a] <= 0) board[x][a]--;
		}
	}
	else {
		for (int a = y - 1; a > -1; a--) {
			if (board[x][a] == 6) break;
			if (board[x][a] <= 0) board[x][a]++;
		}
	}
}

void right(int x, int y, int flag) {
	if (flag == 0) {
		for (int a = y + 1; a < m; a++) {
			if (board[x][a] == 6) break;
			if (board[x][a] <= 0) board[x][a]--;
		}
	}
	else {
		for (int a = y + 1; a < m; a++) {
			if (board[x][a] == 6) break;
			if (board[x][a] <= 0) board[x][a]++;
		}
	}
}

void up(int x, int y, int flag) {
	if (flag == 0) {
		for (int a = x - 1; a > -1; a--) {
			if (board[a][y] == 6) break;
			if (board[a][y] <= 0) board[a][y]--;
		}
	}
	else {
		for (int a = x - 1; a > -1; a--) {
			if (board[a][y] == 6) break;
			if (board[a][y] <= 0) board[a][y]++;
		}
	}
}

void down(int x, int y, int flag) {
	if (flag == 0) {
		for (int a = x + 1; a < n; a++) {
			if (board[a][y] == 6) break;
			if (board[a][y] <= 0) board[a][y]--;
		}
	}
	else {
		for (int a = x + 1; a < n; a++) {
			if (board[a][y] == 6) break;
			if (board[a][y] <= 0) board[a][y]++;
		}
	}
}


void wall_check(int cur, int dir) {
	auto c_num = a[cur].cctv_number;
	if (c_num == 1) {
		if (dir == 0) left(a[cur].x, a[cur].y, 0);
		else if (dir == 1) right(a[cur].x, a[cur].y, 0);
		else if (dir == 2) up(a[cur].x, a[cur].y, 0);
		else if (dir == 3) down(a[cur].x, a[cur].y, 0);
	}
	else if (c_num == 2) {
		if (dir == 0) { left(a[cur].x, a[cur].y, 0); right(a[cur].x, a[cur].y, 0); }
		else if (dir == 1) { up(a[cur].x, a[cur].y, 0); down(a[cur].x, a[cur].y, 0); }
	}
	else if (c_num == 3) {
		if (dir == 0) { right(a[cur].x, a[cur].y, 0); up(a[cur].x, a[cur].y, 0); }
		else if (dir == 1) { right(a[cur].x, a[cur].y, 0); down(a[cur].x, a[cur].y, 0); }
		else if (dir == 2) { left(a[cur].x, a[cur].y, 0); down(a[cur].x, a[cur].y, 0); }
		else if (dir == 3) { left(a[cur].x, a[cur].y, 0); up(a[cur].x, a[cur].y, 0); }
	}
	else if (c_num == 4) {
		if (dir == 0) { left(a[cur].x, a[cur].y, 0); up(a[cur].x, a[cur].y, 0); right(a[cur].x, a[cur].y, 0); }
		else if (dir == 1) { up(a[cur].x, a[cur].y, 0); right(a[cur].x, a[cur].y, 0); down(a[cur].x, a[cur].y, 0); }
		else if (dir == 2) { right(a[cur].x, a[cur].y, 0); down(a[cur].x, a[cur].y, 0); left(a[cur].x, a[cur].y, 0); }
		else if (dir == 3) { down(a[cur].x, a[cur].y, 0); left(a[cur].x, a[cur].y, 0); up(a[cur].x, a[cur].y, 0); }
	}
	else if (c_num == 5) {
		left(a[cur].x, a[cur].y, 0);
		right(a[cur].x, a[cur].y, 0);
		up(a[cur].x, a[cur].y, 0);
		down(a[cur].x, a[cur].y, 0);
	}
	else return;
}

void wall_back(int cur, int dir) {
	int k = a[cur].cctv_number;
	if (k == 1) {
		if (dir == 0) left(a[cur].x, a[cur].y, 1);
		else if (dir == 1) right(a[cur].x, a[cur].y, 1);
		else if (dir == 2) up(a[cur].x, a[cur].y, 1);
		else if (dir == 3) down(a[cur].x, a[cur].y, 1);
	}
	else if (k == 2) {
		if (dir == 0) { left(a[cur].x, a[cur].y, 1); right(a[cur].x, a[cur].y, 1); }
		else if (dir == 1) { up(a[cur].x, a[cur].y, 1); down(a[cur].x, a[cur].y, 1); }
	}
	else if (k == 3) {
		if (dir == 0) { right(a[cur].x, a[cur].y, 1); up(a[cur].x, a[cur].y, 1); }
		else if (dir == 1) { right(a[cur].x, a[cur].y, 1); down(a[cur].x, a[cur].y, 1); }
		else if (dir == 2) { left(a[cur].x, a[cur].y, 1); down(a[cur].x, a[cur].y, 1); }
		else if (dir == 3) { left(a[cur].x, a[cur].y, 1); up(a[cur].x, a[cur].y, 1); }
	}
	else if (k == 4) {
		if (dir == 0) { left(a[cur].x, a[cur].y, 1); up(a[cur].x, a[cur].y, 1); right(a[cur].x, a[cur].y, 1); }
		else if (dir == 1) { up(a[cur].x, a[cur].y, 1); right(a[cur].x, a[cur].y, 1); down(a[cur].x, a[cur].y, 1); }
		else if (dir == 2) { right(a[cur].x, a[cur].y, 1); down(a[cur].x, a[cur].y, 1); left(a[cur].x, a[cur].y, 1); }
		else if (dir == 3) { down(a[cur].x, a[cur].y, 1); left(a[cur].x, a[cur].y, 1); up(a[cur].x, a[cur].y, 1); }
	}
	else if (k == 5) {
		left(a[cur].x, a[cur].y, 1);
		right(a[cur].x, a[cur].y, 1);
		up(a[cur].x, a[cur].y, 1);
		down(a[cur].x, a[cur].y, 1);
	}
	else return;
}

void blind_check(int cur) {
	if (cur == cctv_cnt) {
		int k = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (board[i][j] == 0) k++;
		if (blind_cnt == -1) blind_cnt = k;
		if (blind_cnt > k) blind_cnt = k;
		return;
	}


	for (int i = 0; i < rotation[a[cur].cctv_number - 1]; i++) {
		wall_check(cur, i);
		//cout << "\n";
		//print_board();
		//cout << "\n";
		blind_check(cur + 1);
		wall_back(cur, i);
		//cout << "\n" << blind_cnt << "\n";
		//print_board();
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int k;
			cin >> k;
			if (k > 0 && k < 6) {
				a[cctv_cnt].cctv_number = k;
				a[cctv_cnt].x = i;
				a[cctv_cnt++].y = j;
			}
			board[i][j] = k;
		}
	}
	blind_check(0);
	cout << blind_cnt;
	return 0;
}