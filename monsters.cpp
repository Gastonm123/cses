#include <bits/stdc++.h>
#define limpiar(x) memset(x, -1, sizeof(x))
#define all(x) begin(x),end(x)
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define REP(i, a, n) for(int i = (a); i < (n); i++)
#define c(y,x) ((y)*m+(x))

using namespace std;

const int MAXN = 1e6+5;

bool visitados[MAXN];
bool visitados_monstruos[MAXN];

typedef pair<int,int> ii;

vector<ii> graph[MAXN];
ii P[MAXN];

int main () {
    int n, m;
    cin >> n >> m;

    string mapa[n];
    REP (i, 0, n) {
        cin >> mapa[i];
    }

    REP (i, 0, n) REP (j, 0, m) if (i < n-1 && mapa[i+1][j] != '#') graph[c(i, j)].PB(MP(c(i+1, j), 'D'));
    REP (i, 0, n) REP (j, 0, m) if (j < m-1 && mapa[i][j+1] != '#') graph[c(i, j)].PB(MP(c(i, j+1), 'R'));
    REP (i, 0, n) REP (j, 0, m) if (i > 0 && mapa[i-1][j] != '#') graph[c(i, j)].PB(MP(c(i-1, j), 'U'));
    REP (i, 0, n) REP (j, 0, m) if (j > 0 && mapa[i][j-1] != '#') graph[c(i, j)].PB(MP(c(i, j-1), 'L'));

    vector<int> monstruos;
    vector<int> personaje;
    REP (i, 0, n) REP(j, 0, m) {
        if (mapa[i][j] == 'A') {
            visitados[c(i,j)] = true;
            personaje.PB(c(i,j));
        }
        if (mapa[i][j] == 'M') {
            visitados_monstruos[c(i,j)] = true;
            monstruos.PB(c(i,j));
        }
    }

    int salida;
    limpiar(P);
    try {
        REP (turno, 0, MAXN) {
            // mover personaje
            vector<int> q_personaje = personaje;
            personaje.clear();

            while (q_personaje.size()) {
                int t = q_personaje.back();
                q_personaje.pop_back();

                if (visitados_monstruos[t]) {
                    continue;
                }

                if (t / m == 0 || t / m == n-1 || t % m == 0 || t % m == m-1) {
                    salida = t;
                    throw 10;
                }

                for (auto v : graph[t]) {
                    if (visitados[v.fi] || visitados_monstruos[v.fi])
                        continue;

                    personaje.push_back(v.fi);
                    P[v.fi] = MP(t, v.se);
                    visitados[v.fi] = true;
                }
            }

            // mover monstruos
            vector<int> q_monstruos = monstruos;
            monstruos.clear();

            while (q_monstruos.size()) {
                int t = q_monstruos.back();
                q_monstruos.pop_back();

                for (auto v : graph[t]) {
                    if (visitados_monstruos[v.fi])
                        continue;

                    monstruos.push_back(v.fi);
                    visitados_monstruos[v.fi] = true;
                }
            }
        }
    } catch (int e) {
        // reconstruir camino
        cout << "YES" << endl;

        string camino;
        while (P[salida].fi != -1) {
            camino.PB(P[salida].se);
            salida = P[salida].fi;
        }
        reverse(all(camino));

        cout << camino.size() << endl;
        cout << camino << endl;
        exit(0);
    }

    cout << "NO" << endl;
}