#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

int A[MAX_N], dp[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, Q;
    cin >> N >> M >> Q;

    for (int i = 1; i <= N; i++) cin >> A[i];

    long long sum = 0;
    for (int l = 1, r = 1; l <= N; l++) {
        while (r <= N and sum < M) sum += A[r++];

        if (sum == M) dp[l] = r - 1;
        else dp[l] = N + 1;
        sum -= A[l];
    }
    for (int i = N - 1; i >= 1; i--) dp[i] = min(dp[i], dp[i + 1]);

    while (Q--) {
        int l, r;
        cin >> l >> r;

        if (dp[l] <= r) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}