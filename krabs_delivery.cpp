#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, M, S;
    cin >> N >> M >> S;

    vector <vector <int>> val(100005, vector <int> (N + 5));
    int maxt = 0;
    while (M--) {
        int t, a, b;
        cin >> t >> a >> b;

        maxt = max(maxt, t);
        val[t][a] = b;
    }

    vector <vector <long long>> dp(2, vector <long long> (N + 2, -1));

    dp[0][S] = 0;
    long long ans = 0;
    for (int t = 1; t <= maxt; t++) {
        int now = t % 2, pre = now ^ 1;
        for (int i = 1; i <= N; i++) {
            dp[now][i] = max({dp[pre][i], dp[pre][i - 1], dp[pre][i + 1]});
            if (dp[now][i] >= 0) dp[now][i] += val[t][i];
            ans = max(ans, dp[now][i]);
        }
    }
    cout << ans;
    return 0;
}