#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define forn(i,n) for(int i=0; i<n; i++)
#define all(x) begin(x),end(x)

using namespace std;

typedef pair<int, int> ii; 

int main () {
    int n;
    cin >> n;

    vector<ii> duraciones(n);
    vector<int> deadlines(n);
    forn (i, n) {
        int du, de;
        cin >> du >> de;

        duraciones[i] = mp(du, i);
        deadlines[i]  = de;
    }

    sort(all(duraciones));

    long long k = 0;
    long long time = 0;

    forn (i, n) {
        auto du = duraciones[i];
        time += du.fi;
        k += deadlines[du.se] - time;
    }

    cout << k << endl;
}