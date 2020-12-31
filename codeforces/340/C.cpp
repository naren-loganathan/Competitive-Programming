#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll gcd (ll a, ll b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector <ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector <ll> prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    ll numerator = prefix[n - 1];
    for (ll i = 1; i < n; i++) {
        numerator += 2 * (i * a[i] - prefix[i - 1]);
    }
    ll g = gcd(numerator, n);
    numerator /= g;
    n /= g;
    cout << numerator << " " << n << "\n";
    return 0;
}