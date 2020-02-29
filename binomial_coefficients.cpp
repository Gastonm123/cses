#include <iostream>
#include <vector>
#define forn(i,n) for(int i=0; i<n; i++)
#define all(x) begin(x),end(x)

using namespace std;

const int MOD = 1e9+7;

typedef long long ll;

int factorial_mod(int a) {
    long long f = 1;
    forn (i, a) {
        f *= (i+1);
        f %= MOD;
    }
    return f;
}

int modpow(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2) return (modpow(a, b-1) * a) % MOD;
    return modpow((a*a)%MOD, b/2);
}

int main() {
    int a, b;
    cin >> a >> b;

    if (a < b) {
        cout << "NO CALCULABLE" << endl;
        exit(0);
    }

    int diff = a - b;

    ll f_diff = factorial_mod(diff);
    ll f_a = factorial_mod(a);
    ll f_b = factorial_mod(b);
    cout << f_a << " " << f_b << " " << f_diff << endl;

    ll ans = f_a * modpow((f_b * f_diff) % MOD, MOD-2);
    ans %= MOD;

    cout << ans << endl;
    exit(0);
}