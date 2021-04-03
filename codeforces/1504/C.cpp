#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

bool valid (string &a) {
    bool ans = 1;
    int cntf = 0, cntb = 0;

    for (int i = 0; i < a.length(); i++) {
        (a[i] == '(' ? cntf++ : cntb++);
        if (cntb > cntf) {
            ans = 0; break;
        }
    }
    if (cntf != a.length() / 2) ans = 0;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        if (s.front() == '0' || s.back() == '0') {
            cout << "NO" << '\n';
        } else {
            string a, b;
            for (int i = 0; i < n; i++) {
                a += '('; b += '(';
            }
            a.back() = ')', b.back() = ')';
            bool poss = 1, st = 0;
            int cnt = 0;
            for (int i = 1; i < n - 1; i++) {
                if (s[i] == '0') {
                    if (!st) {
                        a[i] = ')';
                    } else {
                        b[i] = ')';
                    }
                    st = !st;
                    cnt += 1;
                }
            }
            if (cnt % 2) {
                poss = 0;
            } else {
                int cntb = cnt / 2;
                for (int i = n - 1; i > 0; i--) {
                    if (s[i] == '1') {
                        if (cntb < n / 2) {
                            a[i] = ')'; b[i] = ')';
                            cntb += 1;
                        }
                    }
                }
            }
            if (poss && valid(a) && valid(b)) {
                cout << "YES" << '\n' << a << '\n' << b << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}