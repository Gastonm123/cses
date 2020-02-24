#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define forn(i, n) for(int i = 0; i<n;i++)

using namespace std;

int main () {
    int n, x;
    cin >> n >> x;

    int ans = 0;
    vector<int> w(n);
    forn (i, n) {
        cin >> w[i];
    }

    sort(all(w));

    int j = n-1;
    forn (i, n) {
        if (i > j) {
            break;
        }
        while (j > i && w[i] + w[j] > x) ans++, j--;
        ans++;
        j--;
    }

    cout << ans << endl;
}