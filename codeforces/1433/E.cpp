#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define mp make_pair
#define ub upper_bound

ll gcd (ll a, ll b) {
    return (b ? gcd(b, a % b) : a);
}

ll factorial (ll n) {
    return ((n == 1 || n == 0) ? 1 : n * factorial(n - 1));
}

ll ncr (ll n, ll r) {
    ll p = 1, k = 1;
    r = min (n - r, r);
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            ll m = gcd(max(p, k), min(p, k));
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else {
        p = 1;
    }
    return p;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n, ways; 
    cin >> n;
    ways = ncr(n, n / 2) * factorial(n / 2 - 1) * factorial(n / 2 - 1) / 2;
    cout << ways << "\n";
    return 0;
}