#include <bits/stdc++.h>
#define REP(i,a,n) for(int i = (a); i < (n); i++)
#define MP make_pair
#define PB push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

const int MAXN = 1e5+5;

ll distancias[MAXN];
vector<ii> graph[MAXN];

int main () {
    int n, m;
    cin >> n >> m;

    REP (i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].PB(MP(b, c));
    }

    priority_queue<ii> pq;
    pq.push(MP(0, 1));
    
    REP (i, 1, n+1) distancias[i] = 1e15;
    distancias[1] = 0;

    while (pq.size()) {
        ll t = pq.top().se;
        ll dist = -pq.top().fi;
        pq.pop();

        if (distancias[t] < dist) {
            continue;
        }

        for (ii v : graph[t]) {
            if (distancias[v.fi] > v.se + dist) {
                distancias[v.fi] = v.se + dist;
                pq.push(MP(-v.se-dist, v.fi));
            }
        }
    }

    REP (i, 1, n+1) cout << distancias[i] << " ";
    cout << endl;
}