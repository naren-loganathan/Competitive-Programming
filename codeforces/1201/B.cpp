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
    ll n, sum = 0; cin >> n;
    vector <ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort (a.begin(), a.end());
    bool possible = 1;
    if (sum % 2 || a.back() > sum / 2) {
        possible = 0;
    }
    cout << (possible ? "YES" : "NO") << "\n";
    return 0;
}

