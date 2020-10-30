#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
#define fi first
#define se second
#define M 998244353

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k, ways = 1, sum = 0; 
    cin >> n >> k;
    vector <ll> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector <bool> large(n, 0);
    for (int i = 0; i < n; i++) {
        if (p[i] > n - k) {
            large[i] = 1;
            sum += p[i];
        }
    }
    int i = 0;
    while (large[i] != 1) {
        i++;
    }
    i++;
    int j = n - 1;
    while (large[j] != 1) {
        j--;
    }
    j--;
    int length = 0;
    for (;i <= j; i++) {
        if (large[i] == 1) {
            if (large[i - 1] == 0) {
                ways = (ways * (length + 1)) % M;
            }
            length = 0;
        }
        else {
            length++;
        }
    }
    if (length) {
        ways = (ways * (length + 1)) % M;
    }
    cout << sum << " " << ways << "\n";
    return 0;
}