#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int m;
    long long n;
    cin >> m >> n;

    vector <int> t(m);
    for (auto &x : t) cin >> x;

    long long l = 0, r = 1e12, ans;
    while (l <= r) {
        long long mid = (l + r) / 2;

        long long sum = 0;
        for (auto x : t) sum += mid / x;

        if (sum >= n) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}