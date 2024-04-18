#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    map <long long, int> mp;
    mp[0] = 0;
    long long sum = 0, ans = 0;
    int lt = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        sum += a;
        if (mp.count(sum)) lt = max(lt, mp[sum] + 1);
        mp[sum] = i;
        ans += i - lt;
    }
    cout << ans;
    return 0;
}