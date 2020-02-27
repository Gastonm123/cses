#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i<n; i++)

using namespace std;

int main () {
    long long n, t;
    cin >> n >> t;

    vector<long long> tiempos(n);
    forn (i,n) {
        cin >> tiempos[i];
    }

    long long a = -1;
    long long b = 2e18;
    while (a < b-1) {
        long long m = (a+b) / 2; 

        long long produccion = 0;
        forn (i, n) {
            produccion += m / tiempos[i];

            if (produccion >= t) {
                break;
            }
        }

        if (produccion < t) {
            a = m;
        } else {
            b = m;
        }
    }

    cout << b << endl;
}