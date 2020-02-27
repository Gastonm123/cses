#include <bits/stdc++.h>
#define limpiar(x) memset(x, 0, sizeof(x))
#define REP(i, a, n) for(int i=(a); i < (n); i++)

using namespace std;

const int MOD = 1e9+7;

int main () {
    int n, m;
    cin >> n >> m;

    int numeros[n];
    REP (i, 0, n) {
        cin >> numeros[i];
    }

    long long dp[n][m];
    limpiar(dp);
    REP (i, 0, m) {
        if (numeros[0] != 0 && i == numeros[0]-1) {
            dp[0][i] = 1;
        }
        if (numeros[0] == 0) {
            dp[0][i] = 1;
        }
    }

    REP (k, 1, n) {
        REP (i, 0, m) {
            if (numeros[k] != 0 && i == numeros[k]-1) {
                REP (j, -1, 2) {
                    if (j + i >= 0 && j + i < m) {
                        dp[k][i] += dp[k-1][i+j];
                        dp[k][i] %= MOD;
                    }
                }
            }
            if (numeros[k] == 0) {
                REP (j, -1, 2) {
                    if (j + i >= 0 && j + i < m) {
                        dp[k][i] += dp[k-1][i+j];
                        dp[k][i] %= MOD;
                    }
                }
            }
        }
    }

    long long ans = 0;
    if (numeros[n-1] == 0) {
        REP (i, 0, m) {
            ans += dp[n-1][i];
            ans %= MOD;
        }
    } else {
        int i = numeros[n-1] - 1;
        REP (j, -1, 2) {
            if (j + i >= 0 && j + i < m) {
                ans += dp[n-1][i+j];
                ans %= MOD;
            }
        }
    }

    cout << ans << endl;
}