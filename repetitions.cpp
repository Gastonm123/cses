#include <bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    
    int maximo = 1;
    int current = 1;
    forn (i, n) {
        if (i > 0 && s[i-1] == s[i]) {
            current++;
        } else {
            current = 1;
        }

        maximo = max(maximo, current);
    }

    cout << maximo << endl;
}