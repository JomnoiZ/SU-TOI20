#include <bits/stdc++.h>
using namespace std;

multiset <int> R;
multiset <int, greater <int>> L;

void upd() {
    while (L.size() > R.size() + 1) {
        R.insert(*L.begin());
        L.erase(L.begin());
    }
    while (L.size() < R.size()) {
        L.insert(*R.begin());
        R.erase(R.begin());
    }
}

void add(int x) {
    if (L.empty() or x <= *L.begin()) L.insert(x);
    else R.insert(x);
    upd();
}

void remove(int x) {
    if (x <= *L.begin()) L.erase(L.lower_bound(x));
    else R.erase(R.lower_bound(x));
    upd();
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector <int> x(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];

        add(x[i]);
        if (i > k) remove(x[i - k]);
        if (i >= k) cout << *L.begin() << ' ';
    }
    return 0;
}