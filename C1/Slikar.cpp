// Task: https://programming.in.th/tasks/1096
// Tag: Recursion, Divide & Conquer
// Date: 19 April 2024
// Author: JO

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int MXN = 600;

int qs[MXN][MXN];
int n;

int get_one(array<int, 4> pos) {
    auto [tr, br, lc, rc] = pos;
    return qs[br][rc] - qs[br][lc - 1] - qs[tr - 1][rc] + qs[tr - 1][lc - 1];
}

array<int, 4> parse_pos(array<int, 4> &pos, int x) {
    auto [tr, br, lc, rc] = pos;
    int mr = (tr + br)/2;
    int mc = (lc + rc)/2;

    if (x == 0) return {tr, mr, lc, mc};
    else if (x == 1) return {tr, mr, mc + 1, rc};
    else if (x == 2) return {mr + 1, br, lc, mc};
    return {mr + 1, br, mc + 1, rc};
}

int solve(array<int, 4> pos) {
    auto [tr, br, lc, rc] = pos;
    if (tr == br) {
        return 0;
    }

    vector<pair<int ,int>> one(4);
    for (int i = 0; i < 4; i++) {
        one[i] = { solve(parse_pos(pos, i)), get_one(parse_pos(pos, i))};
    }
    
    int res = INF;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) continue;
            int area = (br - tr + 1) * (rc - lc + 1) / 4; 
            int tmp = (area - one[i].second) + one[j].second;
            for (int k = 0; k < 4; k++) {
                if (k == i || k == j) continue;
                tmp += one[k].first;
            }

            res = min(res, tmp);
        }
    }

    return res;    
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char x; cin >> x;
            qs[i][j] = qs[i - 1][j] + qs[i][j - 1] - qs[i - 1][j - 1];
            qs[i][j] += (x == '1');
        }
    }

    cout << solve({1, n, 1, n}) << "\n";    
}