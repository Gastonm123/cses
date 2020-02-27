#include <bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n; i++)

using namespace std;

int main () {
    int n;
    cin >> n;

    vector<int> cubos(n);
    forn (i, n) {
        cin >> cubos[i];
    }

    multiset<int> torres;
    forn (i, n) {
        int a = cubos[i];

        auto it = torres.upper_bound(a);

        if (it == torres.end()) {
            torres.insert(a);
        } else {
            torres.erase(it);
            torres.insert(a);
        }
    }

    cout << torres.size() << endl;
}