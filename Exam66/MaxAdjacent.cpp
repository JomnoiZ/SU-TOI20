#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int x;
    vector <int> a;
    while (cin >> x) a.push_back(x);

    int n = a.size();
    if (n == 1) cout << a[0];
    else {
        for (int i = 0; i < n; i++) {
            if (i == 0 and a[i] > a[i + 1]) cout << a[i] << ' ';
            else if (i == n - 1 and a[i] > a[i - 1]) cout << a[i] << ' ';
            else if (a[i - 1] < a[i] and a[i] > a[i + 1]) cout << a[i] << ' ';
        }
    }
    return 0;
}