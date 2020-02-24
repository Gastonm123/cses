#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define forn(i, n) for(int i=0;i<n;i++)

using namespace std;

int main () {
    int n;
    cin >> n;

    set<int> s;
    forn (i, n) {
        int a;
        cin >> a;
        s.insert(a);
    }

    cout << s.size() << endl;
}