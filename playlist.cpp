#include <bits/stdc++.h>
#define forn(i,n) for(int i =0; i<n;i++)

using namespace std;

int main () {
    int n;
    cin >> n;

    int j = 0;
    int maximo = 0;
    int current = 0;
    vector<int> numeros(n);
    set<int> unicos;
    forn (i, n) {
        int a;
        cin >> a;
        numeros[i] = a;
    }

    forn (i, n) {
        int a = numeros[i];

        if (unicos.count(a)) {
            while (numeros[j++] != a) {
                unicos.erase(numeros[j-1]);
                current--;
            }
            current--;
        } else {
            unicos.insert(a);
        }

        // cout << current << endl;

        current++;
        maximo = max(current, maximo);
    }

    cout << maximo << endl;
}