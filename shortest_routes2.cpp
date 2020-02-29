#include <bits/stdc++.h>
#define REP(i, a, n) for(int i = (a); i < (n); i++)

using namespace std;

typedef long long ll;

int main () {
    int n, m, q;
    cin >> n >> m >> q;

    ll graph[n][n];
    REP (i, 0, n) REP (j, 0, n) graph[i][j] = 1e12;
    REP (i, 0, n) graph[i][i] = 0;

    REP (i, 0, m) {
        ll a, b, c;
        cin >> a >> b >> c;

        a--;
        b--;

        graph[a][b] = min(graph[a][b], c);
        graph[b][a] = min(graph[b][a], c);
    }

    REP (k, 0, n) REP (i, 0, n) REP (j, 0, n) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    REP (i, 0, q) {
        int a, b;
        cin >> a >> b;
        
        a--;
        b--;

        if (graph[a][b] == 1e12) {
            cout << "-1" << endl;
        } else {
            cout << graph[a][b] << endl;
        }
    }
}