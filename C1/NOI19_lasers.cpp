#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int L, R;
    cin >> L >> R;

    vector <int> sz(R + 1);
    vector <vector <int>> walls(R + 1);
    for (int i = 1; i <= R; i++) {
        cin >> sz[i];

        walls[i].resize(sz[i] + 1);
        for (int j = 1; j <= sz[i]; j++) {
            cin >> walls[i][j];
            walls[i][j] += walls[i][j - 1];
        }
    }

    vector <pair <int, int>> events;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= sz[i]; j++) {
            int lm = walls[i][j - 1] + 1;
            int rm = L - (walls[i][sz[i]] - walls[i][j]);
            int cur = walls[i][j] - walls[i][j - 1];
            if (rm - cur + 1 <= lm + cur - 1) {
                events.emplace_back(rm - cur + 1, 1);
                events.emplace_back(lm + cur, -1);
            }
        }
    }

    sort(events.begin(), events.end());

    int lt = -1, ans = 0, sum = 0;
    for (auto [x, v] : events) {
        sum += v;
        if (sum > 0 and lt == -1) lt = x;
        else if (lt != -1 and sum == 0) ans += x - lt, lt = -1;
    }
    cout << ans;
    return 0;
}