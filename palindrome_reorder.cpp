#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define all(x) begin(x),end(x)
#define limpiar(x) memset(x, 0, sizeof(x))
#define forn(i, n) for(int i=0; i<n; i++)

using namespace std;

int main() {
    string s;
    cin >> s;

    int diccionario[26];
    limpiar(diccionario);
    int n = s.size();

    forn (i,n) {
        diccionario[s[i]-'A']++;
    }

    int impar = -1;
    string ans; ans.reserve(n + 5);
    forn (i, 26) {
        if (diccionario[i] % 2) {
            if (impar != -1) {
                cout << "NO SOLUTION" << endl;
                exit(0);
            } else {
                impar = i;
            }
        }
        forn (j, diccionario[i] / 2) {
            ans.push_back(i + 'A');
        }
    }

    string rev = ans;
    reverse(all(rev));

    if (impar != -1) {
        ans.push_back(impar + 'A');
    }

    ans += rev;

    cout << ans << endl;
}