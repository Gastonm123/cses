#include <bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n; i++)

using namespace std;

int main () {
    int n;
    cin >> n;

    long long current = 0;
    long long maximo = 0;

    long long num[n];
    forn (i,n) {
        long long a;
        cin >> a;

        num[i] = a;

        current = max(0ll, current + a);
        maximo = max(maximo, current);
    }

    if (maximo == 0) {
        maximo = -2e9;
        forn (i, n) {
            maximo = max(maximo, num[i]);
        }
    }

    cout << maximo << endl;
}