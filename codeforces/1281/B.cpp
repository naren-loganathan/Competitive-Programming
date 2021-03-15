#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        string s, c; cin >> s >> c;
        vector <int> a(s.length(), s.length() - 1);
        char small = s.back();
        for (int i = s.length() - 2; i >= 0; i--) {
            if (s[i] < small) {
                small = s[i]; a[i] = i;
            } else {
                a[i] = a[i + 1];
            }
        }
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] > s[a[i + 1]]) {
                swap(s[i], s[a[i + 1]]);
                break;
            }
        }
        bool ok = 1, gt = 0; 
        int len = min(s.length(), c.length());
        for (int i = 0; i < len; i++) {
            if (s[i] > c[i]) {
                ok = 0; break;
            } else if (s[i] < c[i]) {
                gt = 1; break;
            }
        }
        if (!gt && ok) {
            ok = (s.length() < c.length() ? 1 : 0);
        }
        if (ok) {
            cout << s << '\n';
        } else {
            cout << "---" << '\n';
        }
    }
    return 0;
}