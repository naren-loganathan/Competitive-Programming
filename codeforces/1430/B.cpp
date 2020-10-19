#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define mp make_pair
#define ub upper_bound

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector <ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll diff_max = a.back();
        for (ll i = n - 2; i >= max((n - k - 1), (ll) 0); i--) {
            diff_max += a[i];
        }
        cout << diff_max << "\n";
    }
    return 0;
}