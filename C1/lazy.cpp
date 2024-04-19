// Task: https://programming.in.th/tasks/codecube_188
// Tag: Binary Search, STL, Map
// Date: 19 April 2024
// Author: JO

#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, Q; cin >> n >> Q;
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        mp[x].emplace_back(i);
    }

    while (Q--) {
        int l, r, C; cin >> l >> r >> C;
        if (mp.find(C) == mp.end()) {
            cout << "0\n";
            continue;
        }

        auto it2 = upper_bound(mp[C].begin(), mp[C].end(), r) ;
        int k2 = it2 - mp[C].begin();

        auto it1 = lower_bound(mp[C].begin(), mp[C].end(), l);
        int k1 = it1 - mp[C].begin();

        cout << k2 - k1 << "\n";
    }
}