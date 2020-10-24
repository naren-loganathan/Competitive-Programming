#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod 1e9 + 7
#define N 1e5 + 5
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; 
    cin >> t;
    while (t--) {
        ll n, m, sum = 0;
        cin >> n >> m;
        vector <ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum == m) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}