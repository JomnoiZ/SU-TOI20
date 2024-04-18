#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int R, C, M;
    cin >> R >> C >> M;

    vector <int> row(R + 1);
    vector <multiset <int>> mts(R + 1);
    vector <set <int>> upd(R + 1);
    vector <vector <int>> table(R + 1, vector <int> (C + 1));
    multiset <int> all_row;
    for (int i = 1; i <= R; i++) {
        mts[i].insert(0);
        all_row.insert(0);
    }

    while (M--) {
        int K, r, c, x;
        cin >> K;

        if (K == 1) {
            cin >> r >> c >> x;

            all_row.erase(all_row.lower_bound(*mts[r].begin()));
            if (upd[r].count(c)) mts[r].erase(mts[r].lower_bound(table[r][c]));
            else {
                upd[r].insert(c);
                if (upd[r].size() == C) mts[r].erase(mts[r].lower_bound(row[r]));
            }
            mts[r].insert(x);
            table[r][c] = x;
            all_row.insert(*mts[r].begin());
        }
        else if (K == 2) {
            cin >> r >> x;

            all_row.erase(all_row.lower_bound(*mts[r].begin()));
            upd[r].clear();
            mts[r].clear();
            row[r] = x;
            mts[r].insert(x);
            all_row.insert(*mts[r].begin());
        }
        else if (K == 3) {
            cin >> r >> c;

            if (upd[r].count(c)) cout << table[r][c] << '\n';
            else cout << row[r] << '\n';
        }
        else cout << *all_row.begin() << '\n';
    }
    return 0;
}