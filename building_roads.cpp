#include <bits/stdc++.h>
#define REP(i, a, n) for(int i = (a); i < (n); i++)
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define limpiar(x) memset(x, -1, sizeof(x))

using namespace std;

const int MAXN = 1e5+5;
vector<int> graph[MAXN];

typedef pair<int ,int> ii;
int colores[MAXN];

void colorear(int nodo, int color) {
    colores[nodo] = color;
    for (int v : graph[nodo]) {
        if (colores[v] == -1) {
            colorear(v, color);
        }
    }
}

int main () {
    int n, m;
    cin >> n >> m;

    REP (i, 0, m) {
        int a, b;
        cin >> a >> b;
        graph[a].PB(b);
        graph[b].PB(a);
    }

    int componente = 0;
    int previa;
    vector<ii> caminos; 
    limpiar(colores);

    REP (i, 1, n+1) {
        if (colores[i] == -1) {
            if (componente > 0) {
                caminos.PB(MP(previa, i));
            }

            colorear(i, componente++);
            previa = i;
        }
    }

    cout << caminos.size() << endl;
    REP (i, 0, caminos.size()) cout << caminos[i].fi << " " << caminos[i].se << endl;
}