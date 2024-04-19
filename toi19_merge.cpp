#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, Q;
    cin >> N >> M >> Q;

    vector <int> x(N + 1), s(N + 1), y(M + 1), t(M + 1);
    for (int i = 1; i <= N; i++) cin >> x[i];
    for (int i = 1; i <= N; i++) cin >> s[i];
    for (int i = 1; i <= M; i++) cin >> y[i];
    for (int i = 1; i <= M; i++) cin >> t[i];

    for (int i = 1; i <= N; i++) s[i] += s[i - 1];
    for (int i = 1; i <= M; i++) t[i] += t[i - 1];

    while (Q--) {
        int a, b, k;
        cin >> a >> b >> k;

        int lp = -1e9, rp = 1e9, ans;
        while (lp <= rp) {
            int midp = (lp + rp) / 2;

            int l = 1, r = N, sx = 0, sy = 0;
            while (l <= r) {
                int mid = (l + r) / 2;

                if (x[mid] <= midp) l = mid + 1, sx = s[mid];
                else r = mid - 1;
            }
            l = 1, r = M;
            while (l <= r) {
                int mid = (l + r) / 2;
                
                if (y[mid] * a + b <= midp) l = mid + 1, sy = t[mid];
                else r = mid - 1;
            }

            if (sx + sy >= k) rp = midp - 1, ans = midp;
            else lp = midp + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}