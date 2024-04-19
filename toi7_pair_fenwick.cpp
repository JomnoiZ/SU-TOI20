#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

int a[MAX_N];

struct Fenwick {
    int n;
    vector <long long> tree;

    Fenwick(int n_) : n(n_), tree(n + 10) {} 

    void add(int x, long long v) {
        for (int i = x; i <= n; i += (i & -i)) tree[i] += v;
    }

    long long get(int x) {
        long long res = 0;
        for (int i = x; i >= 1; i -= (i & -i)) res += tree[i];
        return res;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector <pair <int, int>> vec;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        vec.emplace_back(y, x);
    }

    sort(vec.begin(), vec.end());
    int max_a = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = vec[i - 1].second;
        max_a = max(max_a, a[i]);
    }

    long long ans = 0;
    Fenwick sum(max_a), cnt(max_a);
    for (int i = n; i >= 1; i--) {
        ans += sum.get(a[i] - 1) + cnt.get(a[i] - 1) * a[i];
        sum.add(a[i], a[i]);
        cnt.add(a[i], 1);
    }
    cout << ans;
    return 0;
}