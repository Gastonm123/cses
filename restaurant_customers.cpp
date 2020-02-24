#include <bits/stdc++.h>
#define se second
#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

void insert(map<int,int>& a, int b) {
    if (a.count(b)) {
        a[b]++;
    } else {
        a[b] = 1;
    }
}

int main () {
    int n;
    cin >> n;

    map<int, int> arr;
    map<int, int> lev;
    forn (i, n) {
        int a, b;
        cin >> a >> b;

        insert(arr, a);
        insert(lev, b);
    }

    auto it_arr = arr.begin();
    auto it_lev = lev.begin();

    int maximo = 0;
    int actuales = 0;

    while (it_arr != arr.end() && it_lev != lev.end()) {
        if (it_arr->first <= it_lev->first) {
            actuales += it_arr->se;
            it_arr++;
        } else {
            actuales -= it_lev->se;
            it_lev++;
        }

        maximo = max(maximo, actuales);
    }

    cout << maximo << endl;
}