#include <bits/stdc++.h>
using namespace std;

void solve(int n, int b) {
    if (n == 0) return;

    int t = n % b;
    solve(n / b, b);
    cout << t;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, b;
    cin >> n >> b;

    solve(n, b);
    return 0;
}