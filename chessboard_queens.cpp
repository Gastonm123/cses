#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i<n; i++)

using namespace std;

vector<int> lineas[8];
char tablero[8][8];
bool columna[8];
bool diagonal1[8];
bool diagonal2[8];
int ans = 0;

void search(int y) {
    if (y == 8) {
        ans++;
        return;
    }
    
    if (lineas[y].size()) {
        search(y+1);
        return;
    }

    cout << y << endl;
    forn (i, 8) {
        cout << i << " " << columna[i] << diagonal1[i+y] << diagonal2[7-y+i] << endl;
        if (columna[i] || diagonal1[i+y] || diagonal2[7-y+i]) continue;
        cout << y << " " << i << endl;
        columna[i] = diagonal1[i+y] = diagonal2[7-y+i] = 1;
        search(y+1);
        columna[i] = diagonal1[i+y] = diagonal2[7-y+i] = 0;
    }
}

void poner_reservados(int y) {
    if (y==8) {
        search(0);
        return;
    }
    if (lineas[y].empty()) {
        poner_reservados(y+1);
        return;
    }

    for (int i : lineas[y]) {
        if (columna[i] || diagonal1[i+y] || diagonal2[7-y+i]) continue;
        columna[i] = diagonal1[i+y] = diagonal2[7-y+i] = 1;
        poner_reservados(y+1);
        columna[i] = diagonal1[i+y] = diagonal2[7-y+i] = 0;
    }
}

int main () {
    freopen("a.out", "w", stdout);

    forn (i, 8) forn(j, 8) { 
        cin >> tablero[i][j];
        if (tablero[i][j] == '*') {
            lineas[i].push_back(j);
        } 
    }

    poner_reservados(0);

    cout << ans << endl;
}