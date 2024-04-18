#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5005;
const int MOD = 1e9 + 7;

int A[MAX_N], dp[2][MAX_N], i2c[MAX_N];
vector <int> sum[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, K, c;
    cin >> N >> K >> c;

    for (int i = 1; i <= N; i++) cin >> A[i];

    int L, H;
    cin >> L >> H;

    if (c == 0) i2c[0] = 1;
    for (int i = 1; i <= N; i++) {
        i2c[i] = 1;
        for (int j = 0; j < c; j++) {
            if (1ll * i2c[i] * i > H) break;
            else i2c[i] *= i;
        }
    }

    for (int l = 1; l <= N; l++) {
        if (1ll * i2c[0] * A[l] > H) sum[l].push_back(H + 1);
        else {
            sum[l].push_back(i2c[0] * A[l]);
            for (int r = l + 1; r <= N; r++) {
                if (sum[l].back() + 1ll * i2c[r - l] * A[r] > H) {
                    sum[l].push_back(H + 1);
                    break;
                }
                else sum[l].push_back(sum[l].back() + i2c[r - l] * A[r]);
            }
        }
    }

    dp[0][N + 1] = 1;
    for (int k = 1; k <= K; k++) {
        int now = k % 2, nxt = now ^ 1;
        for (int i = N - k + 1; i >= 1; i--) {
            int l = i, r = min(N - k + 1, (int)sum[i].size() + i - 1), pl = -1, pr = -1;
            while (l <= r) {
                int mid = (l + r) / 2;

                if (sum[i][mid - i] >= L) pl = mid, r = mid - 1;
                else l = mid + 1;
            }

            l = i, r = min(N - k + 1, (int)sum[i].size() + i - 1);
            while (l <= r) {
                int mid = (l + r) / 2;

                if (sum[i][mid - i] <= H) pr = mid, l = mid + 1;
                else r = mid - 1;
            }
            
            if (pl != -1 and pr != -1) dp[now][i] = (dp[nxt][pr + 1] - dp[nxt][pl] + MOD) % MOD;
            else dp[now][i] = 0;
        }
        for (int i = 2; i <= N - k + 1; i++) dp[now][i] = (dp[now][i] + dp[now][i - 1]) % MOD;
    }
    cout << dp[K % 2][1];
    return 0;
}