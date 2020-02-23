#include <bits/stdc++.h>
#define limpiar(a) memset(a, 0, sizeof(a))
#define REP(i, a, n) for(int i=(a); i < (n); i++)

using namespace std;

const int MAXN=1e4+5;

int dx[] = {2, 1, -1, -2, -2, -1};
int dy[] = {-1, -2, -2, -1, 1, 2};

int main() {
    int n;
    cin >> n;

    long long dp[n+1];
    long long c[n+1];
    dp[1] = 0;
    dp[2] = 6;
    c[2] = 0;

    REP (i, 3, n+1) {
        int colisiones= 0;

        REP (p, 0, i) {
            REP (j, 0 , 6) {
                int nx = p + dx[j];
                int ny = 2 + dy[j];

                if (nx < 0 || nx >= i || ny < 0 || ny >= 3)
                    continue;

                colisiones++;
            }
        }

        REP (q, 0, i-1) {
            REP (j, 0 , 6) {
                int nx = 2 + dx[j];
                int ny = q + dy[j];

                if (nx < 0 || nx >= 3 || ny < 0 || ny >= i)
                    continue;
                
                if (ny == i-1) 
                    continue;

                colisiones++;
            }
        }

        long long tem = i * i;
        c[i] = c[i-1] + colisiones;
        dp[i] = (tem * (tem-1) / 2) - c[i];
    }

    REP (i, 0, n) {
        cout << dp[i+1] << endl;
    }
}