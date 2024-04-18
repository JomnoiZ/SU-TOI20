#include <bits/stdc++.h>
using namespace std;

int N, M, K, P;
vector <int> U, V, C, T;
vector <vector <int>> graph;
vector <bool> visited;
int maxVisit;
vector <int> path, ans;

void dfs(int u, int c, int t) {
    if (c > K or t > P) return;

    if (maxVisit < path.size()) {
        maxVisit = path.size();
        ans = path;
    }
    for (auto i : graph[u]) {
        if (visited[V[i]] == true) continue;
        visited[V[i]] = true;
        path.push_back(V[i]);
        dfs(V[i], c + C[i], t + T[i]);
        path.pop_back();
        visited[V[i]] = false;
    }
}

int main() { 
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> M >> K >> P;

    graph.resize(N);
    visited.resize(N);
    U.resize(M);
    V.resize(M);
    C.resize(M);
    T.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> U[i] >> V[i] >> C[i] >> T[i];

        graph[U[i]].push_back(i);
    }

    for (int i = 0; i < N; i++) {
        fill(visited.begin(), visited.end(), false);
        visited[i] = true;
        path.push_back(i);
        dfs(i, 0, 0);
        path.pop_back();
    }

    cout << "Maximum cities reachable: " << maxVisit << '\n';
    cout << "Path:";
    for (auto v : ans) cout << ' ' << v;
    return 0;
}