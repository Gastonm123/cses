#include <iostream>

using namespace std;

int main () {
    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;

        int diff = a - b;

        if (diff > 0) {
            b -= diff;
            a -= 2 * diff;
        } else {
            b += 2 * diff;
            a += diff;
        }

        if (a >= 0 && a % 3 == 0 && b >= 0 && b % 3 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}