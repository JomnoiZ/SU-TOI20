#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6 + 5;

long long tree[2][MAX_N];
string S;

void add(int t, int x, long long v) {
    for (int i = x; i < MAX_N; i += (i & -i)) tree[t][i] += v;
}

long long get(int t, int x) {
    long long res = 0;
    for (int i = x; i >= 1; i -= (i & -i)) res += tree[t][i];
    return res;
}

void add_range(int l, int r, long long x) {
    add(0, l, x);
    add(0, r + 1, -x);
    add(1, l, x * (l - 1));
    add(1, r + 1, -x * r);
}

long long query(int x) {
    return get(0, x) * x - get(1, x);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N >> S;

    S = '#' + S;

    int cntT = 0;
    long long ans = 0;
    stack <int> stk;
    for (int i = 1; i <= N; i++) {
        if (S[i] == 'F') cntT = 0;
        else {
            cntT++;
            int latest = 0;
            if (!stk.empty()) {
                latest = stk.top();
                stk.pop();
            }
            add_range(latest + 1, i, 1);

            if (i + 1 <= N and S[i + 1] == 'F') {
                for (int j = cntT - 1; j >= 0; j--) stk.push(i - j);
            }
        }
        ans += query(i);
    }
    cout << ans;
    return 0;
}