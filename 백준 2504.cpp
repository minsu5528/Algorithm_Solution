#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    stack<char> S;
    int ans = 0;
    int temp = 1;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            temp *= 2;
            S.push('(');
        }
        else if (str[i] == '[') {
            temp *= 3;
            S.push('[');
        }
        else if (str[i] == ')') {
            if (S.empty() || S.top() != '(') {
                cout << 0;
                return 0;
            }
            if (str[i - 1] == '(') ans += temp;
            S.pop();
            temp /= 2;
        }
        else if (str[i] == ']') {
            if (S.empty() || S.top() != '[') {
                cout << 0;
                return 0;
            }
            if (str[i - 1] == '[') ans += temp;
            S.pop();
            temp /= 3;
        }
    }

    if (S.empty()) cout << ans;
    else cout << 0;

    return 0;
}