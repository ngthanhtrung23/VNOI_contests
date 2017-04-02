// Author: happyboy99x

#include<iostream>
#include<cstring>
#include<set>
using namespace std;

const int N = 1000, delta[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char s[2][N][N+1];
int d[2][N][N], m, n;

struct State {
    int map, x, y, d;

    State(const int &map = 0, const int &x = 0, const int &y = 0, const int &d = 0):
        map(map), x(x), y(y), d(d) {}

    bool operator < (const State &s) const {
        return d == s.d ? map == s.map ? x == s.x ? y < s.y : x < s.x : map < s.map : d < s.d;
    }

    bool valid() const {
        return x >= 0 && x < m && y >= 0 && y < n && s[map][x][y] != '#';
    }
};

char& map(const State &t) {
    return s[t.map][t.x][t.y];
}

int& dist(const State &s) {
    return d[s.map][s.x][s.y];
}

void enter() {
    cin >> m >> n;
    for(int map = 0; map < 2; ++map)
        for(int i = 0; i < m; ++i)
            cin >> s[map][i];
}

void update(set<State> &s, const State &st) {
    if(st.valid() && dist(st) > st.d) {
        State temp (st);
        temp.d = dist(st);
        set<State>::iterator it = s.find(temp);
        if(it != s.end()) s.erase(it);
        s.insert(st);
        dist(st) = st.d;
    }
}

int solve() { // Dijkstra
    memset(d, 0x3f, sizeof d);
    set<State> heap;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            if(s[0][i][j] == 'S') {
                d[0][i][j] = 0;
                heap.insert(State(0, i, j, 0));
            }
    while(!heap.empty()) {
        State s (*heap.begin());
        heap.erase(heap.begin());
        if(map(s) == 'T') return s.d;
        for(int k = 0; k < 4; ++k)
            update(heap, State(s.map, s.x + delta[k][0], s.y + delta[k][1], s.d));
        update(heap, State(1 - s.map, s.x, s.y, s.d + 1));
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    enter();
    cout << solve() << "\n";
    return 0;
}
