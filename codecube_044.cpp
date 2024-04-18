#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector <int> a(N + 2), ans(N + 2);
    a[0] = a[N + 1] = INF;
    for (int i = 1; i <= N; i++) cin >> a[i];

    stack <int> stk;
    stk.push(0);
    for (int i = 1; i <= N; i++) {
        while (!stk.empty() and a[stk.top()] <= a[i]) stk.pop();
        ans[i] += i - stk.top();
        stk.push(i);
    }
    stk.push(N + 1);
    for (int i = N; i >= 1; i--) {
        while (!stk.empty() and a[stk.top()] <= a[i]) stk.pop();
        ans[i] += stk.top() - i - 1;
        stk.push(i);
    }
    for (int i = 1; i <= N; i++) cout << ans[i] << ' ';
    return 0;
}