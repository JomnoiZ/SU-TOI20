#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector <long long> A(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];

    long long cur_sum = 0;
    stack <pair <long long, int>> stk;
    vector <long long> L(N + 1), R(N + 1);
    for (int i = 1; i <= N; i++) {
        int cnt = 1;
        while (!stk.empty() and stk.top().first >= A[i]) {
            cur_sum -= stk.top().first * stk.top().second;
            cnt += stk.top().second;
            stk.pop();
        }
        cur_sum += A[i] * cnt;
        stk.emplace(A[i], cnt);
        L[i] = cur_sum;
    }

    while (!stk.empty()) stk.pop();
    cur_sum = 0;
    for (int i = N; i >= 1; i--) {
        int cnt = 1;
        while (!stk.empty() and stk.top().first >= A[i]) {
            cur_sum -= stk.top().first * stk.top().second;
            cnt += stk.top().second;
            stk.pop();
        }
        cur_sum += A[i] * cnt;
        stk.emplace(A[i], cnt);
        R[i] = cur_sum;
    }

    long long ans = 0;
    for (int i = 1; i <= N; i++) ans = max(ans, L[i] + R[i] - A[i]);
    cout << ans;
    return 0;
}