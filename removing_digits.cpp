#include <bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n;i++)

using namespace std;

int main () {
    int n;
    cin >> n;

    int dp[n+1];
    forn (i, n+1) dp[i] = 1e9;
    dp[0] = 0;

    forn (i, n+1) {
        for (int d = i; d > 0; d /= 10) {
            int dig = d % 10;
            dp[i] = min(dp[i], dp[i-dig]+1);
        }
    }

    cout << dp[n] << endl;
}