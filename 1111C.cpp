#include <bits/stdc++.h>
using namespace std;

int n, k, A, B;
vector <int> a;

long long solve(int l, int r) {
    int cnt = upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);
    if (cnt == 0) return A;

    long long cost = 1ll * cnt * (r - l + 1) * B;
    int mid = (l + r) / 2;
    if (l < r) cost = min(cost, solve(l, mid) + solve(mid + 1, r));
    return cost;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> k >> A >> B;

    a.resize(k);
    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end());
    cout << solve(1, 1<<n);
    return 0;
}