#include <iostream>
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
        int n, k; cin >> n >> k;
        bool possible = 1;
        string s; cin >> s;
        for (int i = 0; i < k; i++) {
            if (s[i] != s[n - 1 - i]) possible = 0;
        }
        if (possible) {
            if (n % 2 == 0 && k == n / 2) {
                possible = 0;
            }
        }
        cout << (possible ? "YES" : "NO") << '\n';
    }
    return 0;
}