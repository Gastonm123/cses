#include <iostream>

using namespace std;

const int modulo = 1e9+7;

int main() {
    int n;
    cin >> n;

    long long ans = 1;
    while (n--) {
        ans <<= 1;
        ans %= modulo;
    }

    cout << ans;
}