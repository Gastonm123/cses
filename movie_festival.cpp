#include <bits/stdc++.h>
#define mp make_pair
#define forn(i,n) for(int i=0; i<n; i++)
#define all(x) begin(x),end(x)
#define start second
#define finish first

using namespace std;

typedef pair<int ,int> ii;

int main () {
    int n;
    cin >> n;

    vector<ii> movies(n);
    forn (i, n) {
        int a, b;
        cin >> a >> b;

        movies[i] = mp(b, a);
    }

    sort(all(movies));

    int current_time = 0;
    int seen = 0;

    forn (i, n) {
        auto m = movies[i];
        if (current_time <= m.start) {
            current_time = m.finish;
            seen++;
        }
    }

    cout << seen << endl;
}