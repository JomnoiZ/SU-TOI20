#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

int A[MAX_N];

void solve(int l, int r) {
    if (l == r) return;

    int mid = (l + r) / 2;
    solve(l, mid);
    solve(mid + 1, r);

    vector <int> tmp(r - l + 1);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid or j <= r) {
        if (i == mid + 1) tmp[k++] = A[j++]; // i สุดทาง
        else if (j == r + 1) tmp[k++] = A[i++]; // j สุดทาง
        else if (A[i] <= A[j]) tmp[k++] = A[i++]; // i is better than j
        else tmp[k++] = A[j++]; // j is better than i
    }
    for (int i = 0; i < r - l + 1; i++) A[l + i] = tmp[i];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) cin >> A[i];

    solve(1, N);

    for (int i = 1; i <= N; i++) cout << A[i] << ' ';
    return 0;
}