#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i<n; i++)

using namespace std;

int main () {
    int x, n;
    cin >> x >> n;

    set<int> luces; luces.insert(x);
    multiset<int> rangos; rangos.insert(x);

    vector<int> ans(n);
    forn (i, n) {
        int a;
        cin >> a;

        auto it = luces.lower_bound(a);

        int v_it = *it;
        int v_an;
        if (it != luces.begin()) {
            it--;
            v_an = *it;
        } else {
            v_an = 0;
        }

        int rango_it = v_it - v_an;

        auto rango_eliminar = rangos.find(rango_it);
        rangos.erase(rango_eliminar);

        // cout << rango_it << endl;
        rangos.insert(a - v_an);
        rangos.insert(v_it - a);

        luces.insert(a);

        ans[i] = *(rangos.rbegin()); 
    }

    forn (i, n)
        cout << ans[i] << " ";
    cout << endl;
}