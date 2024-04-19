#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;

int a[MAX_N];

long long solve(int l, int r) {
    if (l == r) return 0;

    int mid = (l + r) / 2;
    long long cnt = solve(l, mid) + solve(mid + 1, r);

    vector <int> L, R;
    for (int i = l; i <= mid; i++) L.push_back(a[i]);
    for (int i = mid + 1; i <= r; i++) R.push_back(a[i]);

    int i = 0, j = 0, k = l;
    while (i < L.size() and j < R.size()) {
        if (L[i] < R[j]) {
            a[k] = L[i];
            cnt += j;
            i++, k++;
        }
        else {
            a[k] = R[j];
            j++, k++;
        }
    }
    while (i < L.size()) {
        a[k] = L[i];
        cnt += j;
        i++, k++;
    }
    while (j < R.size()) {
        a[k] = R[j];
        j++, k++;
    }    
    return cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) cin >> a[i];

        cout << solve(1, n) << '\n';
    }
    return 0;
}