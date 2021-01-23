#include <iostream>
#include <string>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int count (string &s, int l, int r, char c) {
    int result = 0;
    for (int i = l; i <= r; i++) {
        if (s[i] != c) {
            result++;
        }
    }
    return result;
}

int min_for_good (string &s, int l, int r, char c) {
    if (r == l) {
        return (s[l] == c ? 0 : 1);
    }
    int mid = (l + r) / 2;
    int cntl = count(s, mid + 1, r, c) + min_for_good(s, l, mid, c + 1);
    int cntr = count(s, l, mid, c) + min_for_good(s, mid + 1, r, c + 1);
    return min(cntl, cntr);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        cout << min_for_good(s, 0, n - 1, 'a') << "\n";
    }
    return 0;
}
