#include <iostream>
#include <vector>
#include <algorithm>
#define all(x) begin(x), end(x)

using namespace std;

int main() {
    string s;
    cin >> s;

    sort(all(s));

    vector<string> permutaciones;
    do {
        permutaciones.push_back(s);
    } while(next_permutation(all(s)));

    cout << permutaciones.size() << endl;
    for (string t : permutaciones) {
        cout << t << endl;
    }
}