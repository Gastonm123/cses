#include <bits/stdc++.h>
#define REP(i, a, n) for(int i = (a); i < (n); i++)

using namespace std;

const int MOD = 1e9+7;

int main () {
    int n;
    cin >> n;

    vector<long long> dp(n+1, 0);
    dp[0] = 1;
    REP (i, 1, n+1) {
        REP (j, max(0, i-6), i) {
            dp[i] += dp[j];
            dp[i] %= MOD;
        }
    }

    cout << dp[n] << endl;
}