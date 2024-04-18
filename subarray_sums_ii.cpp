#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, x;
    cin >> n >> x;

    long long sum = 0, ans = 0;
    map <long long, int> mp;
    mp[0] = 1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        sum += a;
        ans += mp[sum - x];
        mp[sum]++;
    }
    cout << ans;
    return 0;
}