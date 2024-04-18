#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector <vector <pair <int, int>>> graph(N);
    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].emplace_back(v, w);
    }

    int s;
    cin >> s;

    vector <int> dist(N, INF), parent(N);

    priority_queue <pair <int, int>> pq;
    pq.emplace(0, s);
    dist[s] = 0;
    parent[s] = s;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto [v, w] :  graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.emplace(-dist[v], v);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (i == s) continue;

        cout << s << " -> " << i << " (";
        if (dist[i] == INF) cout << "inf)\n";
        else {
            cout << dist[i] << ')';
            stack <int> stk;
            int u = i;
            while (u != s) {
                stk.push(u);
                u = parent[u];
            }
            stk.push(s);
            for (; !stk.empty(); stk.pop()) cout << ' ' << stk.top();
            cout << '\n';
        }
    }
    return 0;
}