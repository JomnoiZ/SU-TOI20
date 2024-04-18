#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int D, K;
    cin >> D >> K;

    priority_queue <int> pq;
    long long ans = 0;
    for (int d = 0; d < D; d++) {
        int N, B;
        cin >> N >> B;

        for (int i = 0; i < N; i++) {
            int a;
            cin >> a;

            pq.push(a - d * K);
        }
        while (B--) {
            ans += d * K + pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';
    return 0;
}