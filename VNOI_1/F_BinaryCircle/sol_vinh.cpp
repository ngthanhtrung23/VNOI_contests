#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int n;
vector <string> s;

int main() {
    cin >> n;
    s.pb("00"); s.pb("01"); s.pb("10"); s.pb("11");
    for (int i = 3; i <= n; i++) {
        if (i % 2 == 1) {
            vector <string> tmp;
            for (int i = 0; i < s.size(); i++) tmp.pb('0' + s[i]);
            for (int i = 0; i < s.size(); i++) tmp.pb('1' + s[i]);
            s = tmp;
        }
        if (i % 2 == 0) {
            vector <string> tmp;
            for (int i = 0; i < s.size(); i++) {
                if (i % 2 == 0) tmp.pb('0' + s[i]);
                else tmp.pb('1' + s[i]);
            }
            for (int i = 0; i < s.size(); i++) {
                if (i % 2 == 0) tmp.pb('1' + s[i]);
                else tmp.pb('0' + s[i]);
            }
            s = tmp;
        }
    }
    for (int i = 0; i < s.size(); i++) cout << s[i] << endl;
}
