#include <bits/stdc++.h>
#define REP(i, a, n) for(int i = (a); i < (n); i++)
#define limpiar(x) memset(x, -1, sizeof(x))
#define PB push_back

using namespace std;

const int MAXN = 1e5+5;

int colores[MAXN];
bool visitado[MAXN];
vector<int> graph[MAXN];

bool colorear(int nodo, int color) {
    colores[nodo] = color;
    for (int v : graph[nodo]) {
        if (colores[v] == -1) {
            colorear(v, !color);
        } else if (colores[v] == color) {
            throw 10;
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

    limpiar(colores);
    try {
        REP (i, 1, n+1) if (colores[i] == -1) colorear(i, 1);
        REP (i, 1, n+1) cout << colores[i]+1 << " ";
        cout << endl;
    } catch (int e) {
        cout << "IMPOSSIBLE" << endl;
    }
}