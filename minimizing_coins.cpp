#include <bits/stdc++.h>
#define REP(i, a, n) for(int i=(a); i<(n); i++)
#define limpiar(i) memset(i, -1, sizeof(i))

using namespace std;

int main () {
    int n, x;
    cin >> n >> x;

    vector<int> monedas(n);
    REP (i, 0, n) {
        cin >> monedas[i];
    }

    int dp[x+1];
    // dp[0] = 0;
    limpiar(dp);
    dp[0] = 0;
    REP (i, 0, x+1) {
        // cout << dp[i] << endl;
        if (dp[i] == -1)
            continue;

        REP (j, 0, n) {
            // cout << i + monedas[j] << endl;
            if (i + monedas[j] <= x) {
                if (dp[i+monedas[j]] == -1) {
                    dp[i+monedas[j]] = dp[i]+1;
                } else {
                    dp[i+monedas[j]] = min(dp[i+monedas[j]], dp[i]+1);
                }
            }
        }
    }

    cout << dp[x] << endl;
}