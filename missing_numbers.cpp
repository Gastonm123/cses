#include <bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define limpiar(x) memset(x, 0, sizeof(x))

using namespace std;

int main() {
    int n;
    cin >> n;

    bool numeros[n];
    limpiar(numeros);
    int j = 0;
    forn (i, n) {
        int x;
        cin >> x;

        x--;

        numeros[x] = 1;

        while(numeros[j]) j++;
    }

    cout << j+1 << endl;
}