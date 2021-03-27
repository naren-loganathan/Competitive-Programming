#include <iostream>
#include <string>
#include <vector>
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
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int beg = 0, end = n - 1;
        while (s[beg] != '*') beg += 1;
        while (s[end] != '*') end -= 1;
        if (beg == end) {
            cout << 1 << '\n';
        } else {
            int i = beg, ans = 1;
            while (s[end] != 'x') {
                s[i] = 'x';
                for (int j = min(end, i + k); j > i; j--) {
                    if (s[j] == '*') {
                        ans += 1;
                        i = j; break;
                    }
                }
            }
            //-_-
            cout << ans << '\n';
        }
    }
    return 0;
}