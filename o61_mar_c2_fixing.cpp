#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;

    vector <int> A(M + 1);
    for (int i = 1; i <= M; i++) cin >> A[i];
    
    int sum = 0;
    vector <int> vec;
    for (int i = 2; i <= M; i++) {
        sum += A[i] - A[i - 1] - 1;
        vec.push_back(A[i] - A[i - 1] - 1);
    }

    sort(vec.rbegin(), vec.rend());

    for (int i = 0; i < min(K, M) - 1; i++) sum -= vec[i];
    cout << sum;
    return 0;
}