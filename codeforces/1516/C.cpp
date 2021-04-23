#include <iostream>
#include <vector>
#include <map>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll gcd(ll a, ll b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, sum = 0, g = 0; 
    cin >> n;
    vector <ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        g = gcd(a[i], g); sum += a[i];
    }
    sum /= g;
    for (int i = 0; i < n; i++) {
        a[i] /= g;
    }
    if (sum % 2) {
        cout << '0' << '\n';
    } else {
        vector <int> reachable(sum + 1);
        reachable[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = sum; j >= 0; j--) {
                if (reachable[j]) {
                    reachable[j + a[i]] = 1;
                }
            }
        }
        if (reachable[sum / 2] == 0) {
            cout << '0' << '\n';
        } else {
            cout << '1' << '\n';
            for (int i = 0; i < n; i++) {
                if (a[i] % 2) {
                    cout << (i + 1) << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}