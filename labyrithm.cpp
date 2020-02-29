#include <bits/stdc++.h>
#define REP(i, a, n) for(int i=(a); i < (n); i++)
#define MP make_pair
#define PB push_back
#define se second
#define fi first
#define all(x) begin(x), end(x)
#define c(y, x) ((y)*m+(x))
#define limpiar(x) memset(x, -1, sizeof(x))

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, char> ic;

const int MAXN = 1e6;
bool visitados[MAXN];
vector<ic> graph[MAXN];
string solucion;
ic P[MAXN];

int main () {
    int n, m;
    cin >> n >> m;

    string mapa[n];
    REP (i, 0, n) cin >> mapa[i];

    REP (i, 0, n) REP (j, 0, m) if (i < n-1 && mapa[i+1][j] != '#') graph[c(i, j)].PB(MP(c(i+1,j), 'D'));
    REP (i, 0, n) REP (j, 0, m) if (j < m-1 && mapa[i][j+1] != '#') graph[c(i, j)].PB(MP(c(i,j+1), 'R'));
    REP (i, 0, n) REP (j, 0, m) if (i > 0 && mapa[i-1][j] != '#') graph[c(i, j)].PB(MP(c(i-1,j), 'U'));
    REP (i, 0, n) REP (j, 0, m) if (j > 0 && mapa[i][j-1] != '#') graph[c(i, j)].PB(MP(c(i,j-1), 'L'));

    int inicio, B;
    REP (i, 0, n) REP (j, 0, m) {
        if (mapa[i][j] == 'A') inicio = c(i, j); 
        if (mapa[i][j] == 'B') B = c(i, j);
    }

    queue<int> q;
    q.push(inicio);
    limpiar(P);

    while (q.size()) {
        int t = q.front();
        q.pop();

        if (t == B) 
            break;

        for (ii v : graph[t]) {
            if (P[v.fi].fi == -1) {
                P[v.fi] = MP(t, v.se);
                q.push(v.fi);
            }
        }
    }

    if (P[B].fi != -1) {
        cout << "YES" << endl;

        int current = B;
        while (current != inicio) {
            solucion.PB(P[current].se);
            current = P[current].fi;
        } 

        cout << solucion.size() << endl;
        reverse(all(solucion));
        cout << solucion << endl;
    } else {
        cout << "NO" << endl;
    }
}