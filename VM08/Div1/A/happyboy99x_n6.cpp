#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;

void brute(int x, int y, int s) {
    int res = 0, cnt = 0;
    for(int ax = 0; ax <= x; ++ax) for(int ay = 0; ay <= y; ++ay)
        for(int bx = ax; bx <= x; ++bx) for(int by = bx == ax ? ay + 1 : 0; by <= y; ++by)
            for(int cx = bx; cx <= x; ++cx) for(int cy = cx == bx ? by + 1 : 0; cy <= y; ++cy) {
              cnt++;
              if (abs((bx - ax) * (cy - ay) - (by - ay) * (cx - ax)) == 2 * s) ++res;
            }
    cout << res << "\n";
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int x, y, s; cin >> x >> y >> s; s *= 2;
    brute(x, y, s/2);
    return 0;
}

