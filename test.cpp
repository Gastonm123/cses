#include <iostream>
#include <vector>
#define forn(i,n) for(int i=0; i<n; i++)
#define all(x) begin(x),end(x)

using namespace std;

int main() {
    string s; s.reserve(10);
    s.push_back('A');
    s.push_back('B');
    s.push_back('C');
    s.push_back('D');
    s.push_back('E');

    cout << s << endl;

    vector<int> ans;
    forn (i, 50) {
        ans.push_back(i);
    }

    string r(all(ans));

    cout << r << endl;
}