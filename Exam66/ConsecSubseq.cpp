#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int x;
    set <int> s;
    while (cin >> x) s.insert(x);

    int p, cnt = 1, a1 = 0, a2 = 0;
    bool st = false;
    for (auto x : s) {
        if (st == false) st = true;
        else if (p + 1 == x) cnt++;
        else cnt = 1;
        if (a1 < cnt) a1 = cnt, a2 = x;
        p = x;
    }
    for (int i = a2 - a1 + 1; i <= a2; i++) cout << i << ' ';
    return 0;
}