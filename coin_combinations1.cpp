#include <bits/stdc++.h>
#define forn(i, n) for(int i=0; i<n;i++)
#define limpiar(x) memset(x, 0, sizeof(x))

using namespace std;

const int MOD = 1e9+7;

int main () {
    int n, x;
    cin >> n >> x;

    int monedas[n];
    forn (i, n) {
        cin >> monedas[i];
    }

    long long dp[x+1];
    limpiar(dp);
    dp[0] = 1;

    forn (i, x+1) {
        forn (j, n) {
            if (i + monedas[j] <= x) {
                dp[i + monedas[j]] += dp[i];
                dp[i + monedas[j]] %= MOD;
            }
        }
    }

    cout << dp[x] << endl;
}