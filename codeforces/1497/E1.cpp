#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /*vector <bool> prime(1e7 + 1, 1);
    vector <int> sm(1e7 + 1, 0);
    for (int i = 2; i <= 1e7; i++) {
        sm[i] = 2;
    }
    for (int i = 3; i <= 1e7; i += 2) {
        if (prime[i]) {
            sm[i] = i;
            for (int j = i; j * j <= N; j += 2) {
                if (prime[i * j] == 1) {
                    prime[i * j] = 0;
                    sm[i * j] = i;
            }
        }
    }*/
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int ans = 1;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector <int> modulo(n, 1);
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            while (a[i] % 2 == 0) {
                a[i] /= 2; cnt += 1;
            }
            if (cnt % 2) {
                modulo[i] *= 2;
            }
            for (int j = 3; j * j <= a[i]; j += 2) {
                if (a[i] % j == 0) {
                    int cnt = 0;
                    while (a[i] % j == 0) {
                        a[i] /= j; cnt += 1;
                    }
                    if (cnt % 2) {
                        modulo[i] *= j;
                    }
                }
            }
            if (a[i] > 1) {
                modulo[i] *= a[i];
            }
        }
        /*for (int i = 0; i < n; i++) {
            cout << modulo[i] << ' ';
        }
        cout << '\n';*/
        set <int> s;
        for (int i = 0; i < n; i++) {
            if (s.find(modulo[i]) != s.end()) {
                ans += 1;
                s.clear();
            }
            s.insert(modulo[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}