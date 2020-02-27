#include <bits/stdc++.h>

#define forn(i, n) for(int i=0;i<n;i++)
#define all(x) begin(x),end(x)
#define limpiar(x) memset(x, 0, sizeof(x))

using namespace std;

const int MOD = 1e9+7;

int main () {
    int n, x;
    cin >> n >> x;

    vector<int> numeros(n);
    forn (i, n) {
        cin >> numeros[i];
    }

    sort(all(numeros));
    long long dp[x+1];
    limpiar(dp);
    dp[0] = 1;

    forn (k, n) {
        forn (i, x+1) {
            if (i + numeros[k] <= x) {
                dp[i+numeros[k]] += dp[i];
                dp[i+numeros[k]] %= MOD;
            }
        }
    }

    cout << dp[x] << endl;
}