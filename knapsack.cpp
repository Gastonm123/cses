#include <bits/stdc++.h>
#define PER(i,a,n) for(int i=(n)-1; i>=(a); i--)
#define forn(i,n) for(int i=0; i<(n); i++)
#define REP(i,a,n) for(int i=(a); i<(n); i++)

using namespace std;

int main () {
    int n, W;
    cin >> n >> W;

    // int W = 0;

    int w[n+1];
    int v[n+1];

    forn (i, n) {
        cin >> w[i+1];
        // W += w[i+1];
    }

    forn (i, n) {
        cin >> v[i+1];
    }

    int dp[W+1];
    
    forn (i, W+1) dp[i] = -1e9;
    dp[0] = 0;

    REP (k, 1, n+1) {
        PER (i, 0, W+1) {
            if (i + w[k] <= W) {
                dp[i+w[k]] = max(dp[i+w[k]], dp[i]+v[k]);
            }
        }
        // forn(i, W+1) cout << dp[i] << " ";
        // cout << endl;
    }

    int maximo = 0;
    forn (i, W+1) {
        maximo = max(maximo, dp[i]);
    }

    cout << maximo << endl;
}