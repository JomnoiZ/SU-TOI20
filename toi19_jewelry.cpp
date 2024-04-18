#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    char S[n + 5] = {};
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }

    long long ans = 0;
    long long sum = 0;
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        if (S[i] == 'T') {
            int prev = 0;
            if (!st.empty()) prev = st.top(), st.pop();
            sum += i - prev;

            if (i + 1 <= n and S[i + 1] == 'F') {
                int start = 0;
                for (int j = i; S[j] == 'T' and j >= 1; j--) start = j;
                for (int j = start; j <= i; j++) st.push(j);
            }
        }

        ans += sum;
    }

    cout << ans << "\n";
}