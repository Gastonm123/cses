#include <bits/stdc++.h>
#define REP(i, a, n) for(int i=(a); i < (n); i++)
#define c(y, x) ((y)*m+(x))

using namespace std;

const int MAXN = 1e6;
int colores[MAXN];
vector<int> graph[MAXN];

void colorear(int nodo, int color) {
    colores[nodo] = color;
    for (auto v : graph[nodo]) {
        if (colores[v] == 0)
            colorear(v, color);
    }
}

int main () {
    int n, m;
    cin >> n >> m;

    string mapa[n];
    REP (i, 0, n) {
        cin >> mapa[i];
    }

    REP (i, 0, n) REP (j, 0, m) if (j < m-1 && mapa[i][j+1] == '.') graph[c(i, j)].push_back(c(i, j+1));
    REP (j, 0, m) REP (i, 0, n) if (i < n-1 && mapa[i+1][j] == '.') graph[c(i, j)].push_back(c(i+1, j));
    REP (i, 0, n) REP (j, 0, m) if (j > 0 && mapa[i][j-1] == '.') graph[c(i, j)].push_back(c(i, j-1));
    REP (j, 0, m) REP (i, 0, n) if (i > 0 && mapa[i-1][j] == '.') graph[c(i, j)].push_back(c(i-1, j));

    int cuartos = 0;
    REP (i, 0, n) REP (j, 0, m) if (mapa[i][j] == '.' && colores[c(i, j)] == 0) colorear(c(i, j), ++cuartos);
    
    cout << cuartos << endl;
}