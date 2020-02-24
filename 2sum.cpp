#include <bits/stdc++.h>
#define forn(i, n) for(int i =0; i<n; i++)
#define all(x) begin(x), end(x)
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef pair<int ,int> ii;

int main () {
    int n, x;
    cin >> n >> x;

    vector<ii> a(n);
    forn (i, n) {
        int in;
        cin >> in;

        a[i] = mp(in, i);
    }

    sort(all(a));

    int j = n-1;
    ii ans = mp(-1, -1);

    forn (i, n) {
        while (j > i && a[i].fi + a[j].fi > x) j--;
        if (i >= j) break;
        if (a[i].fi + a[j].fi == x) {
            ans = mp(a[i].se, a[j].se);
            break;
        } 
    }

    if (ans.fi == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << ans.fi+1 << " " << ans.se+1 << endl;
    }
}