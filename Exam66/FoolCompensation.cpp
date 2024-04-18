#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector <pair <int, int>> b;
    int pa = -1, a;
    for (int i = 1; i <= N; i++) {
        cin >> a;

        if (a != pa) b.emplace_back(a, 1);
        else b.back().second++;
        pa = a;
    }

    vector <int> idx(b.size());
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](const int &x, const int &y) {
        return b[x].first < b[y].first;
    });

    int sum = 0;
    vector <int> cost(b.size());
    for (int i = 0; i < b.size(); i++) {
        cost[idx[i]] = 1;
        if (idx[i] > 0 and b[idx[i] - 1].first < b[idx[i]].first) cost[idx[i]] = max(cost[idx[i]], cost[idx[i] - 1] + 1);
        if (idx[i] < b.size() - 1 and b[idx[i] + 1].first < b[idx[i]].first) cost[idx[i]] = max(cost[idx[i]], cost[idx[i] + 1] + 1);
        sum += cost[idx[i]] * b[idx[i]].second;
    }
    cout << sum * 1000ll;
    return 0;
}