#include <bits/stdc++.h>
#define forn(i, n) for(int i=0;i<n;i++)

using namespace std;

int main () {
    string s1;
    string s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    n++;
    m++;

    int dp[n][m];
    forn (i, n) forn(j, m) dp[i][j] = 1e9;
    dp[0][0] = 0;

    forn (i, n) {
        forn (j, m) {
            if (i < n-1) {
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
            }

            if (j < m-1) {
                dp[i][j+1] = min(dp[i][j+1], dp[i][j]+1);
            }

            if (i < n-1 && j < m-1) {
                int costo = (s1[i] != s2[j]);
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+costo);
            }
        }
    }

    cout << dp[n-1][m-1] << endl;
}