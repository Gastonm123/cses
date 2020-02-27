#include <bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define all(x) begin(x),end(x)

using namespace std;

int main () {
    int n;
    cin >> n;

    vector<int> numeros(n);
    forn (i, n) {
        cin >> numeros[i];
    }

    sort(all(numeros));

    int medio = n / 2;
    int median = numeros[medio-1];

    long long costo = 0;
    forn (i, n) {
        costo += abs(median - numeros[i]);
    }

    cout << costo << endl;
}