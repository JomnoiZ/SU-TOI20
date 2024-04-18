#include <bits/stdc++.h>
using namespace std;

void testcase() {
    int n;
    cin >> n;

    multiset <int> subset_sum;
    for (int i = 0; i < (1<<n); i++) {
        int a;
        cin >> a;

        subset_sum.insert(a);
    }

    vector <int> ans, possible_sum;
    subset_sum.erase(subset_sum.begin());
    while (!subset_sum.empty()) {
        int cur = *subset_sum.begin();
        subset_sum.erase(subset_sum.begin());

        ans.push_back(cur);
        int sz = possible_sum.size();
        possible_sum.push_back(cur);
        for (int i = 0; i < sz; i++) {
            possible_sum.push_back(cur + possible_sum[i]);
            subset_sum.erase(subset_sum.lower_bound(cur + possible_sum[i]));
        }
    }
    for (auto v : ans) cout << v << ' ';
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    cin >> t;
    
    while (t--) testcase();
    return 0;
}