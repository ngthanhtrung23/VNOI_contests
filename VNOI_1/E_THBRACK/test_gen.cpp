#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; ++i)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; --i)
#define REP(i,a) for(int i=0,_a=(a); i < _a; ++i)

#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define PR(A,n)  { cout << #A << " = "; FOR(_,1,n) cout << A[_] << ' '; cout << endl; }
#define PR0(A,n) { cout << #A << " = "; REP(_,n) cout << A[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define ll long long
#define __builtin_popcount __builtin_popcountll
#define SZ(x) ((int) (x).size())
using namespace std;

double safe_sqrt(double x) {
    return sqrt(max((double)0.0,x));
}
int GI(ll& x) {
    return scanf("%lld", &x);
}

int test = 0;

void gen(int len, int rem) {
    string s = "";
    int open = 0;
    REP(i,len) {
        int left = len - i - 1;
        char cur = ' ';
        if (open+1 > left) {
            cur = ')';
        }
        else if (open == 0) {
            cur = '(';
        }
        else {
            if (rand() % 2 == 0) cur = '(';
            else cur = ')';
        }
        s += cur;
        if (cur == '(') ++open;
        else --open;
        assert(open >= 0);
    }
    assert(open == 0);

    vector<int> id; REP(i,len) id.push_back(i);
    random_shuffle(id.begin(), id.end());

    REP(i,rem) {
        s[id[i]] = '?';
    }

    stringstream ss; ss << "gen_rr/" << test++ << ".in";
    fstream fout(ss.str(), fstream :: out);
    fout << s << endl;
    REP(i,rem) fout << rand() % 1000 + 1 << ' ' << rand() % 1000 + 1 << endl;
    fout.close();
}

#undef int
int main() {
#define int long long
    ios :: sync_with_stdio(0); cin.tie(0);
    cout << (fixed) << setprecision(9);
    gen(50000, 0);
    gen(50000, 100);
    gen(50000, 500);
    gen(50000, 1000);
    gen(50000, 2000);
    gen(50000, 5000);
    gen(50000, 10000);
    gen(50000, 20000);
    gen(50000, 40000);
    gen(50000, 50000);
}

