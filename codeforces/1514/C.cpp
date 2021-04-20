#include <iostream>
#include <vector>
#include <cmath>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector <ll> inc(n, 1), ans, factors;
    ll x = n;
    if (x % 2 == 0) {
        factors.push_back(2);
        while (x % 2 == 0) x /= 2;
    }
    for (int i = 3; i <= ceil(sqrt(x)); i += 2) {
        if (x % i == 0) {
            factors.push_back(i);
            while (x % i == 0) x /= i;
        }
    }
    if (x != 1) factors.push_back(x);
    for (int i = 2; i < n; i++) {
        for (int j = 0; j < factors.size(); j++) {
            if (i % factors[j] == 0) inc[i] = 0;
        }
    }
    for (ll i = 1; i < n; i++) {
        if (inc[i]) ans.push_back(i);
    }
    ll pdt = 1;
    for (int i = 0; i < ans.size(); i++) {
        pdt = (pdt * ans[i]) % n;
    }
    if (pdt != 1) ans.pop_back();
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}