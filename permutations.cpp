#include <bits/stdc++.h>
#define REP(i,a,n) for(int i=(a); i<(n); i++)
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 2 || n == 3)
        cout << "NO SOLUTION" << endl,
        exit(0);

    deque<int> d;
    d.push_back(1);

    if (n > 3) {
        d.push_back(3);
        d.push_front(4);
        d.push_front(2);

        REP (i, 5, n+1) {
            if(i % 2)
                d.push_back(i);
            else
                d.push_front(i);
        }
    }

    for (int a : d) {
        cout << a << " ";
    }
    cout << endl;
}