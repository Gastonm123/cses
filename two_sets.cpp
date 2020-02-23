#include <bits/stdc++.h>
#define PER(i, a, n) for(int i=(n)-1; i >= (a); i--) 

using namespace std;

int main () {
    long long n;
    cin >> n;

    long long sum = n * (n + 1) / 2;
    if (sum % 2)
        cout << "NO" << endl,
        exit(0);

    long long half = sum / 2;
    vector<int> a;
    vector<int> b;

    PER (i, 1, n+1) {
        if (half - i < 0)
            b.push_back(i);
        else {
            half -= i;
            a.push_back(i);
        }
    } 

    cout << "YES" << endl;
    
    cout << a.size() << endl;
    PER (i, 0, a.size()) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << b.size() << endl;
    PER (i, 0, b.size()) {
        cout << b[i] << " ";
    }
    cout << endl;
}