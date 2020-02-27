#include <bits/stdc++.h>
#define REP(i, a, n) for(int i = (a); i < (n); i++)

using namespace std;

int main () {
    int n, m;
    cin >> n >> m;

    if (n < m)
        swap(n, m);

    int dp[n+1][m+1];
    REP (i, 0, n+1) REP(j, 0, m+1) dp[i][j] = 1e9;

    REP (i, 1, n+1) {
        REP (j, 1, min(i+1, m+1)) {
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }

            REP (k, 1, i) {
                int l = i - k;
                int costo_corte = dp[max(k, j)][min(k, j)] + dp[max(l, j)][min(l, j)] + 1;

                dp[i][j] = min(dp[i][j], costo_corte);
            }

            REP (k, 1, j) {
                int l = j - k;
                int costo_corte = dp[max(k, i)][min(k, i)] + dp[max(l, i)][min(l, i)] + 1;

                dp[i][j] = min(dp[i][j], costo_corte);
            }
        }
    }

    cout << dp[n][m] << endl;
}