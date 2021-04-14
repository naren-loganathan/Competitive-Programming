#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector <ll> sod(1e7 + 1, 1);
    for (int i = 2; i <= 1e7; i++) {
        for (int j = i; j <= 1e7; j += i) {
            sod[j] += i;
        }
    }
    vector <int> s(1e7 + 1);
    for (int i = 1; i <= 1e7; i++) {
        if (sod[i] <= 1e7) {
            if (!s[sod[i]]) {
                s[sod[i]] = i;
            }
        }
    }
    int t; cin >> t;
    while (t--) {
        int c; cin >> c;
        cout << (s[c] ? s[c] : -1) << '\n';
    }
    return 0;
}