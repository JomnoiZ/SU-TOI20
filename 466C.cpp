#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector <int> a(n + 1);
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    long long ans = 0;
    if (sum % 3 == 0) {
        int way = 0;
        long long cnt = 0;
        for (int i = 1; i < n; i++) {
            cnt += a[i];
            if (cnt == 2 * sum / 3) ans += way;
            if (cnt == sum / 3) way++;
        }
    }
    cout << ans;
    return 0;
}