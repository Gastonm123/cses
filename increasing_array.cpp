#include <bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

const int MAXN = 2e5+5;
int numeros[MAXN];

int main(){
    int n;
    cin >> n;

    long long turnos = 0;
    forn (i,n) {
        cin >> numeros[i];
        if (i > 0 && numeros[i-1] > numeros[i]) {
            turnos += numeros[i-1] - numeros[i];
            numeros[i] = numeros[i-1];
        }
    }

    cout << turnos << endl;
}