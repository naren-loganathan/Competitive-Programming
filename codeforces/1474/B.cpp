#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector <bool> sieve(5e4 + 1, 1);
    for (ll p = 2; p * p <= 5e4; p++) {
        if (sieve[p]) {
            for (ll i = p * p; i <= 5e4; i += p) {
                sieve[i] = 0;
            }
        }
    }
    vector <ll> primes;
    for (ll i = 2; i <= 5e4; i++) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
    int t; cin >> t;
    while (t--) {
        int d; cin >> d;
        int it1 = lower_bound(primes.begin(), primes.end(), d + 1) - primes.begin();
        int it2 = lower_bound(primes.begin(), primes.end(), primes[it1] + d) - primes.begin();
        cout << primes[it1] * primes[it2] << "\n";
    }
    return 0;
}