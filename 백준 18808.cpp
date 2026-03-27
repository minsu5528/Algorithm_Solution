#include <bits/stdc++.h>
using namespace std;

int n, m;
int cnt;

bool board[50][50];
bool stick[12][12];

void rotation(int row, int col) {
	bool copy_stick[12][12];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			copy_stick[i][j] = stick[i][j];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			stick[j][i] = copy_stick[row - i - 1][j];
}

bool check_board(int i, int j, int row, int col) {
	for (int a = 0; a < row; a++) {
		for (int b = 0; b < col; b++) {
			if (board[i + a][j + b] && stick[a][b])
				return false;
		}
	}
	for (int a = 0; a < row; a++)
		for (int b = 0; b < col; b++)
			if (stick[a][b] == 1) board[i + a][j + b] = stick[a][b];
	return true;

}

bool check_stick(int row, int col) {
	if (row > n || col > m) return false;
	for (int i = 0; i <= n - row; i++) {
		for (int j = 0; j <= m - col; j++) {
			if (check_board(i, j, row, col)) return true;
		}
	}
	return false;
}

void func(int row, int col) {

	for (int i = 0; i < 4; i++) {
		if (check_stick(row, col)) return;
		else {
			rotation(row, col);
			swap(row, col);
		}
	}

	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> cnt;
	for (int i = 0; i < cnt; i++) {
		int row, col;
		cin >> row >> col;
		for (int a = 0; a < row; a++)
			for (int b = 0; b < col; b++)
				cin >> stick[a][b];
		func(row, col);



	}

	int stick_cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] == 1) stick_cnt++;
	cout << stick_cnt << "\n";
	return 0;
}