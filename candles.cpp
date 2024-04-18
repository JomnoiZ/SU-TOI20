#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector <int> x(N + 1);
    for (int i = 1; i <= N; i++) cin >> x[i];

    int ans = INF;
    for (int i = K; i <= N; i++) {
        if (x[i] <= 0) ans = min(ans, -x[i - K + 1]);
        else if (x[i - K + 1] >= 0) ans = min(ans, x[i]);
        else ans = min(ans, x[i] - x[i - K + 1] + min(x[i], -x[i - K + 1]));
    }
    cout << ans;
    return 0;
}