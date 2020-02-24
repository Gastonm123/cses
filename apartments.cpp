#include <bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define all(x) begin(x),end(x)

using namespace std;

int main () {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> ap(n);
    forn (i, n) {
        cin >> ap[i];
    }

    vector<int> si(m);
    forn (i, m) {
        cin >> si[i];
    }

    sort(all(ap));
    sort(all(si));

    int a = 0, s = 0;
    int satisfechos = 0;
    for (;a<n;a++) {
        while (s < m && ap[a] - si[s] > k) s++;
        if (s < m && abs(ap[a] - si[s]) <= k) {
            satisfechos++;
            s++;
        }
    }

    cout << satisfechos << endl;
}