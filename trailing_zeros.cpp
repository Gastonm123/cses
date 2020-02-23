#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int zeros = 0;
    for (long long m = 5, i = 1; m <= n; m *= 5, i++) {
        int ap_m = n / m;
        int zeros_m = (ap_m / 5 * 4) + ap_m % 5;

        zeros += zeros_m * i;
    }

    cout << zeros << endl;
}