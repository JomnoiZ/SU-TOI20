#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    vector <vector <string>> dp(n + 1, vector <string> (n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
            else if (dp[i - 1][j].size() > dp[i][j - 1].size()) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = dp[i][j - 1];
        }
    }

    cout << dp[n][n] << '\n' << dp[n][n].size() << '\n';
    if (dp[n][n].size() > n / 2) cout << 'y';
    else cout << 'n';
    return 0;
}