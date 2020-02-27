#include <bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n;i++)
#define limpiar(x) memset(x, 0, sizeof(x))

using namespace std;

const int MOD = 1e9+7;

int main () {
    int n;
    cin >> n;

    char mapa[n][n];
    forn (i, n) {
        string s;
        cin >> s;

        forn (j, n) {
            mapa[i][j] = s[j];
        }
    }

    long long dp[n][n];
    limpiar(dp);
    if (mapa[0][0] != '*')
        dp[0][0] = 1;

    forn (i, n) {
        forn (j, n) {
            if (mapa[i][j] == '*') {
                continue;
            }

            if (i < n-1) {
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= MOD;
            }

            if (j < n-1) {
                dp[i][j+1] += dp[i][j];
                dp[i][j+1] %= MOD;
            }
        }
    }

    int ans = 0;
    if (mapa[n-1][n-1] != '*') {
        ans = dp[n-1][n-1];
    }

    cout << ans << endl;
}