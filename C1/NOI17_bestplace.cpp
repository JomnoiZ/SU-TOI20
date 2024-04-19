#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector <int> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    cout << x[n / 2] << ' ' << y[n / 2];
    return 0;
}