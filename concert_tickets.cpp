#include <bits/stdc++.h>
#define se second
#define all(x) begin(x),end(x)
#define forn(i,n) for(int i=0; i<n; i++)
#define mp(a,b) make_pair(a,b)

using namespace std;

typedef pair<int ,int> ii;

int main () {
    int n, m;
    cin >> n >> m;

    multiset<int> precios;
    forn (i, n) {
        int a;
        cin >> a;
        precios.insert(a);
    }

    forn (i, m) {
        int c;
        cin >> c;

        auto it = precios.lower_bound(c);

        if (it == precios.end() || *it > c) {
            if (it == precios.begin()) {
                cout << -1 << endl;
                continue;
            }
            it--;
        }

        cout << *it << endl;
        precios.erase(it);
    }
}