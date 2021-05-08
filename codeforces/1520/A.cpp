#include <iostream>
#include <vector>
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
        int n; cin >> n;
        string s; cin >> s;
        bool sus = 0;
        vector <int> cnt(26);
        int i = 0;
        while (i < n) {
            if (cnt[s[i] - 'A']) {
                sus = 1; break;
            } else {
                char c = s[i];
                while (s[i] == c && i < n) {
                    i += 1;
                    cnt[c - 'A'] += 1;
                }
            }
        }
        cout << (sus ? "NO" : "YES") << '\n';
    }
    return 0;
}