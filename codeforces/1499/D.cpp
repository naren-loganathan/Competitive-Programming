#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int N = 2e7 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //p -> number of distinct prime divisors
    //s -> smallest divisor (always a prime)
    vector <int> p(N), s(N, -1);
    for (int i = 2; i < N; i++) {
        if (s[i] == -1) {
            for (int j = i; j < N; j += i) {
                if (s[j] == -1) {
                    s[j] = i;
                }
            }
        }
    }
    for (int i = 2; i < N; i++) {
        int j = i / s[i];
        p[i] = p[j] + (s[i] != s[j]);
    }
    int t; cin >> t;
    while (t--) {
        int c, d, x, ans = 0;
        cin >> c >> d >> x;
        for (int i = 1; i * i <= x; i++) {
            int n1 = i + d, n2 = x / i + d;
            if (x % i == 0) {
                if (n1 % c == 0) {
                    ans += 1 << p[n1 / c];
                }
                if (i * i != x && n2 % c == 0) {
                    ans += 1 << p[n2 / c];
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}