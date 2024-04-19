#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    vector <int> p(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
        p[i] += p[i - 1];
    }
    for (int i = N - 1; i >= 1; i--) p[i] = min(p[i], p[i + 1]);
    
    while (Q--) {
        int q;
        cin >> q;

        int l = 0, r = N, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (p[mid] <= q) l = mid + 1, ans = mid;
            else r = mid - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}