// Task: https://programming.in.th/tasks/o58_oct_c1_evergreen
// Tag: Binary Search, Math, Observation
// Date: 19 April 2024
// Author: JO
/* 
Notes:
 Observe overlapping cases for consecutive bushes.
 There are 2 cases where difference between consecutive bushes are odd and even
 For odd distance: the overlapping area = k * (k + 1) 
 For even distance: the overlapping area = k * k
 Where k is the number of day that bushes are overlapped
*/

#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e3 + 10;

int n;
long long target;
int x[MXN];

bool check(int D) {
    long long ans = 1ll * D * D;    
    for (int i = 2; i <= n; i++) {
        ans += 1ll * D * D;
        int dis = x[i] - x[i - 1] - 1;
        long long k = max(0, D - (x[i] - x[i - 1] + 1)/2);
        long long sub = (dis%2 ? k*k : k*(k + 1));
        ans -= sub;
    }
    return (ans >= target);
}

int main() {
    cin >> n >> target;
    
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    sort(x + 1, x + n + 1);

    int l = 1, r = 1e9, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans - 1 << "\n";
}
