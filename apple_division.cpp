#include <iostream>
#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

int main() {
    int n;
    cin >> n;

    int pesos[n];
    long long suma = 0;

    forn (i, n) {
        cin >> pesos[i];
        suma += pesos[i];
    }

    long long minimo = suma;
    forn (i, 1<<n) {
        long long peso_grupo = 0;

        forn (j, n) {
            if (i>>j & 1) {
                peso_grupo += pesos[j];
            }
        }

        long long diferencia = abs(2 * peso_grupo - suma); 
        minimo = min(minimo, diferencia);
    }

    cout << minimo << endl;
}