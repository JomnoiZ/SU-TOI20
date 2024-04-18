#include <bits/stdc++.h>
using namespace std;

char solve(unsigned long long n, unsigned long long x) {
    unsigned long long m = (n - 1) / 3;
    if (x <= m) return solve(m, x);
    if (x == m + 1) return 'P';
    if (x <= 2 * m + 1) return solve(m, x - m - 1) == 'P' ? 'A' : 'P';
    return solve(m, x - 2 * m - 1);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        unsigned long long n;
        cin >> n;

        unsigned long long sz = 1;
        while (sz < n) sz = 3 * sz + 1;

        cout << solve(sz, n) << '\n';
    }
    return 0;
}