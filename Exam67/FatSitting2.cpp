#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 6005;
const int INF = 1e9 + 7;

int N;
vector <int> graph[MAX_N];
int distP[MAX_N], distS[MAX_N];

void bfs(int *dist, vector <int> &s) {
    for (int i = 1; i <= N; i++) dist[i] = INF;

    queue <int> q;
    for (auto &v : s) {
        q.push(v);
        dist[v] = 0;
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto &v : graph[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int P, S;
    cin >> N;
    
    cin >> P;
    vector <int> sP(P);
    for (auto &x : sP) cin >> x;

    cin >> S;
    vector <int> sS(S);
    for (auto &x : sS) cin >> x;

    for (int i = 1; i <= N; i++) {
        int m;
        cin >> m;

        while (m--) {
            int v;
            cin >> v;

            graph[i].push_back(v);
        }
    }
    
    bfs(distP, sP);
    bfs(distS, sS);

    int B;
    cin >> B;

    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= B; i++) {
        int r;
        cin >> r;

        if (distP[r] < distS[r]) ans1++;
        else if (distP[r] > distS[r]) ans2++;
    }
    cout << ans1 << ' ' << ans2 << ' ' << B - ans1 - ans2;
    return 0;
}