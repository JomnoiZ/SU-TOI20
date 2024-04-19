#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;

    vector <int> e(N + 1);
    for (int i = 1; i <= N; i++) cin >> e[i];

    long long l = 0, r = 1e12, ans;
    while (l <= r) {
        long long mid = (l + r) / 2;

        int cnt = 0;
        long long sum = 0;
        priority_queue <int, vector <int>, greater <int>> pq;
        for (int i = 1; i <= N; i++) {
            sum += e[i];
            pq.push(e[i]);
            if (pq.size() > K) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == K and sum >= mid) {
                sum = 0;
                while (!pq.empty()) pq.pop();
                cnt++;
            }
        }

        if (cnt >= M) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}