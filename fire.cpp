#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;

int V[MAX_N][MAX_N];
vector <int> vec[2 * MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> V[i][j];
            vec[i + j - 1].push_back(V[i][j]);
        }
    }

    int ans = 0;
    priority_queue <int> pq;
    for (int i = 2 * N - 1; i >= 2; i--) {
        for (auto v : vec[i]) pq.push(v);

        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
    return 0;
}