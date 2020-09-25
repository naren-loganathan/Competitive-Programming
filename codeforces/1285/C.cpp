#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define pb push_back

ll gcd(ll a, ll b) {
    ll r;
    while (a != 0) {
        r = b % a;
        b = a;
        a = r;
    }
    return b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x;
    cin >> x;
    ll a = x, b = x;
    for (ll i = 1; i * i <= x; i++){
        if (x % i == 0 && gcd(i, x / i) == 1) {
            if (max(i, x / i) <= b) {
                b = max (i, x / i);
                a = min (i, x / i);
            }
        }
    }
    cout << a << ' ' << b << endl;
    return 0;
}