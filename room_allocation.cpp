#include <bits/stdc++.h>
#define fi first
#define forn(i,n) for(int i=0; i<n; i++)
#define all(x) begin(x),end(x)
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> ii;

int main () {
    int n;
    cin >> n;

    vector<ii> arr(n);
    vector<ii> lev(n);
    forn (i, n) {
        int a, l;
        cin >> a >> l;

        arr[i] = mp(a, i);
        lev[i] = mp(l, i);
    }

    sort(all(arr));
    sort(all(lev));

    int i = 0;
    int j = 0;

    // map<int, int> cuartos;
    set<int> cuartos_libres;

    vector<int> cuartos(n);
    int cant_cuartos = 0;

    while (i < n || j < n) {
        if (i < n && arr[i].fi <= lev[j].fi) {
            // proceso i
            ii a = arr[i++];
            if (cuartos_libres.empty()) {
                cuartos[a.se] = ++cant_cuartos;
            } else {
                int libre = *cuartos_libres.begin();
                cuartos_libres.erase(cuartos_libres.begin());
                cuartos[a.se] = libre;
            }
        } else {
            // proceso j
            ii l = lev[j++];
            cuartos_libres.insert(cuartos[l.se]);
        }
    }

    cout << cuartos_libres.size() << endl;
    forn (i, n) 
        cout << cuartos[i] << " ";
    cout << endl;
}