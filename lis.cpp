#include <bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define se second
#define fi first

using namespace std;

int main() {
    int n;
    cin >> n;

    int numeros[n];
    forn (i,n) {
        cin >> numeros[i];
    }

    int dp[n];
    set<pair<int, int> > anteriores;

    forn (k, n) {
        dp[k] = 1;
        auto it = anteriores.lower_bound(make_pair(numeros[k], 0));

        if (anteriores.size() && it != anteriores.begin()) {
            it--;
            dp[k] = it->se+1;
        }

        anteriores.insert(make_pair(
            numeros[k], dp[k]
        ));
    }

    int maximo = 0;
    forn (i, n) {
        if (maximo < dp[i]) {
            cout << i << endl;
        }
        maximo = max(maximo, dp[i]);
    }

    cout << maximo << endl;
}