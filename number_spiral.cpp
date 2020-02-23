#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        long long x, y;
        cin >> y >> x;

        long long numero = 0;
        if (y > x) {
            if (y % 2) {
                y--;
                numero = y * y + x;
            } else {
                numero = y * y - x + 1;
            }
        } else {
            if (x % 2) {
                numero = x * x - y + 1;
            } else {
                x--;
                numero = x * x + y;
            }
        }

        cout << numero << endl;
    }
}