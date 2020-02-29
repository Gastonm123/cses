#include <bits/stdc++.h>
#define PER(i,a,n) for(int i=(n)-1; i >= (a); i--)
#define all(x) begin(x),end(x)
#define fi first
#define se second
#define REP(i,a,n) for(int i=(a); i<(n); i++)
#define PB push_back
#define MP make_pair
#define limpiar(x) memset(x, -1, sizeof(x))

using namespace std;

typedef pair<int,int> ii;

const int MAXN = 1e5+5;
int P[MAXN];
vector<int> graph[MAXN];

vector<int> path(int nodo) {
    vector<int> ans;
    while (nodo != -1) {
        ans.push_back(nodo);
        nodo = P[nodo];
    }
    return ans;
}

int main () {
    int n, m;
    cin >> n >> m;

    REP (i, 0, m) {
        int a, b;
        cin >> a >> b;

        graph[a].PB(b);
        graph[b].PB(a);
    }

    ii ans;
    limpiar(P);
    try {
        REP (i, 1, n+1) {
            if (P[i] != -1)
                continue;

            queue<int> q;
            q.push(i);

            while(q.size()) {
                int t = q.front();
                q.pop();

                for (int v : graph[t]) {
                    if (v == P[t]) {
                        continue;
                    }
                    if (P[v] != -1) {
                        ans = MP(t , v);
                        throw 0;
                    } else {
                        P[v] = t;
                        q.push(v);
                    }
                }
            }
        }
    } catch (int e) {
        auto path_fi = path(ans.fi);
        auto path_se = path(ans.se);

        reverse(all(path_fi));
        reverse(all(path_se));

        int lca = 0;
        for (;path_fi[lca] == path_se[lca]; lca++);
        lca--;

        cout << path_fi.size() + path_se.size() - 2 * lca << endl;
        REP (i, lca, path_fi.size()) cout << path_fi[i] << " ";
        PER (i, lca, path_se.size()) cout << path_se[i] << " ";
        cout << endl;
        exit(0);
    }

    cout << "IMPOSSIBLE" << endl;
}