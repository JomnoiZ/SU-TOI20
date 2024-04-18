#include <bits/stdc++.h>
using namespace std;

void testcase() {
    int n, q;
    cin >> n >> q;

    vector <int> c(n + 1), one(n + 1);
    vector <long long> qs(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];

        qs[i] = qs[i - 1] + c[i];
        one[i] = one[i - 1] + (c[i] == 1);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        
        if (l == r or one[r] - one[l - 1] + r - l + 1 > qs[r] - qs[l - 1]) cout << "NO\n";
        else cout << "YES\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 1;
    cin >> t;

    while (t--) testcase();
    return 0;
}