// Author: lexuanan
// Algo: Loang theo lop

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int hi[] = {0, 0, -1, 1};
const int hj[] = {-1, 1, 0, 0};

const int N = 1005;

int m, n;
int head = 0, tail = -1;
pair<pair<int,int>,int> q[N*N*2];
bool mark[N][N][2];
char s[2][N][N];
int d[N][N][2];
pair<int,int> bd, kt;

void them(int i, int j, int k) {
    mark[i][j][k] = true;
    q[++tail] = {{i,j},k};
    for (int z = 0; z < 4; z++) {
        int ii = i + hi[z];
        int jj = j + hj[z];
        if (ii <= 0 || ii > m || jj <= 0 || jj > n) continue;
        if (!mark[ii][jj][k] && s[k][ii][jj] == '.') {
            d[ii][jj][k] = d[i][j][k];
            them(ii,jj,k);
        }
    }
}

int main() {
    scanf("%d%d", &m, &n);

    for (int i = 1; i <= m; i++) {
        scanf("%s", s[0][i]+1);
        for (int j = 1; j <= n; j++)
            if (s[0][i][j] == 'S') {
                bd = {i,j};
                s[0][i][j] = '.';
            }
            else if (s[0][i][j] == 'T') {
                kt = {i,j};
                s[0][i][j] = '.';
            }
    }

    for (int i = 1; i <= m; i++)
        scanf("%s", s[1][i]+1);

    them(bd.first, bd.second, 0);

    while (head <= tail) {
        int i = q[head].first.first;
        int j = q[head].first.second;
        int k = q[head].second;
        head++;

        if (i == kt.first && j == kt.second && k == 0) break;

        for (int z = 0; z < 4; z++) {
            int ii = i + hi[z];
            int jj = j + hj[z];
            if (ii <= 0 || ii > m || jj <= 0 || jj > n || s[k^1][ii][jj] != '.' || mark[ii][jj][k^1]) continue;
            d[ii][jj][k^1] = d[i][j][k]+1;
            them(ii,jj,k^1);
        }
    }

    printf("%d", d[kt.first][kt.second][0]);
}
