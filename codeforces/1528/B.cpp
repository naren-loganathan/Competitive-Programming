#include <iostream>
#include <vector>
#include <map>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll mod = 998244353;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector <int> sieve(1e6 + 1, -1);
    for (int i = 2; i <= 1e6; i++) {
        if (sieve[i] == -1) {
            for (int j = i; j <= 1e6; j += i) {
                sieve[j] = i;
            }
        }
    }
    int n; cin >> n;
    vector <ll> a(n + 1), p(n + 1);
    a[0] = 1; p[0] = 1;
    a[1] = 1; p[1] = 2;
    for (int j = 2; j <= n; j++) {
        int x = j, cnt = 1;
        map <ll, ll> div;
        while (x > 1) {
            div[sieve[x]]++;
            x /= sieve[x];
        }
        map <ll, ll> :: iterator it;
        for (it = div.begin(); it != div.end(); it++) {
            cnt = (cnt * (it -> se + 1)) % mod;
        }
        cnt--;
        a[j] = (cnt + p[j - 1]) % mod;
        p[j] = (a[j] + p[j - 1]) % mod;
    }
    cout << a.back() << '\n';
    return 0;
}