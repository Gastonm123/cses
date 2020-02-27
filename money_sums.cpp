#include <bits/stdc++.h>
#define limpiar(x) memset(x, 0, sizeof(x))
#define PER(i, a, n) for(int i = (n) - 1; i >= (a); i--)
#define REP(i, a, n) for(int i = a; i < n; i++)
using namespace std;

const int MAXM = 1e5+5;

int dp[MAXM];

int main () {
    int n;
    cin >> n;

    int monedas[n];
    REP (i, 0, n) {
        cin >> monedas[i];
    }

    limpiar(dp);
    dp[0] = 1;

    REP (k, 0, n) {
        PER (i, 0, MAXM) {
            if (i + monedas[k] < MAXM) {
                dp[i+monedas[k]] |= dp[i];
            }
        }
    }

    vector<int> posibles;
    REP (i, 1, MAXM) {
        if (dp[i])
            posibles.push_back(i);
    }

    cout << posibles.size() << endl;
    REP (i, 0, posibles.size())
        cout << posibles[i] << " ";
    cout << endl;
}