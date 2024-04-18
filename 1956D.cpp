#include <bits/stdc++.h>
using namespace std;

void solve(int l, int r, vector <int> &a, vector <pair <int, int>> &ans) {
    if (l > r) return;
    for (int i = l; i <= r; i++) {
        if (a[i] == i - l) continue;
        ans.emplace_back(l, i);
        for (int j = l; j <= i; j++) a[j] = i - l;
        solve(l, i - 1, a, ans);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector <int> a(n);
    for (auto &x : a) cin >> x;

    int ans = 0, ans_mask = 0;
    for (int mask = 0; mask < (1<<n); mask++) {
        int sum = 0, lt = 0;
        for (int i = 0; i < n; i++) {
            if (!(mask & (1<<i))) continue;
            sum += a[i] + (i - lt) * (i - lt);
            lt = i + 1;
        }
        sum += (n - lt) * (n - lt);
        if (ans < sum) ans = sum, ans_mask = mask;
    }

    int lt = 0;
    vector <pair <int, int>> ans_op;
    for (int i = 0; i <= n; i++) {
        if (!(ans_mask & (1<<i))) continue;
        if (lt < i) {
            solve(lt, i - 1, a, ans_op);
            ans_op.emplace_back(lt, i - 1);
            for (int j = lt; j < i; j++) a[j] = i - lt;
        }
        lt = i + 1;
    }
    if (lt < n) {
        solve(lt, n - 1, a, ans_op);
        ans_op.emplace_back(lt, n - 1);
        for (int j = lt; j < n; j++) a[j] = n - lt;
    }

    cout << ans << ' ' << ans_op.size() << '\n';
    for (auto [l, r] : ans_op) cout << l + 1 << ' ' << r + 1 << '\n';
    return 0;
}