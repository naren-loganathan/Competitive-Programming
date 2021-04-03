#include <iostream>
#include <string>
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
        string s; cin >> s;
        bool poss = 0, pal = 1;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] != 'a') poss = 1;
            if (s[i] != s[n - 1 - i]) pal = 0;
        }
        if (!poss) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
            if (pal) {
                cout << 'a' << s << '\n';
            } else {
                cout << s.substr(0, n / 2) << 'a' << s.substr(n / 2, n / 2 + (n % 2)) << '\n';
            }
        }
    }
    return 0;
}