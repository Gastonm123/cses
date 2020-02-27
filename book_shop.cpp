#include <bits/stdc++.h>
#define PER(i, a, n) for(int i=(n)-1; i>=a; i--)
#define forn(i,n) for(int i=0;i<n;i++)
#define limpiar(x) memset(x, 0, sizeof(x))

using namespace std;

int main () {
    int n, x;
    cin >> n >> x;

    int precio[n];
    int paginas[n];
    forn (i, n) {
        cin >> precio[i];
    }
    forn (i, n) {
        cin >> paginas[i];
    }

    int dp[x+1];
    limpiar(dp);
    
    forn (k, n) {
        PER (i, 0, x+1) {
            if (i + precio[k] <= x) {
                dp[i+precio[k]] = max(dp[i+precio[k]], paginas[k] + dp[i]);
            }
        }

        // forn (i, x+1) {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
    }

    int maximo = 0;
    forn (i, x+1) {
        maximo = max(maximo, dp[i]);
    }

    cout << maximo << endl;
}