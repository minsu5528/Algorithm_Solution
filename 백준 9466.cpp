#include <bits/stdc++.h>
using namespace std;

int board[100005];
bool vis[100005];  // 방문 여부
bool done[100005]; // 탐색 종료 여부 (중복 탐색 방지)
int cnt;           // 사이클에 포함된 학생 수

void dfs(int curr) {
    vis[curr] = true;
    int next = board[curr];

    if (!vis[next]) {
        dfs(next);
    }
    else if (!done[next]) {
        // 방문은 했지만 탐색이 끝나지 않았다면 사이클 발견!
        // 사이클을 이루는 노드 개수를 직접 셉니다.
        for (int i = next; i != curr; i = board[i]) {
            cnt++;
        }
        cnt++; // 자기 자신 포함
    }

    done[curr] = true; // 현재 노드 탐색 완료
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        fill(vis + 1, vis + n + 1, false);
        fill(done + 1, done + n + 1, false);
        for (int i = 1; i <= n; i++) cin >> board[i];

        cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) dfs(i);
        }
        // 전체 인원 - 사이클에 포함된 인원 = 팀을 못 만든 사람
        cout << n - cnt << "\n";
    }
}