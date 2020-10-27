#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define N 100005
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
        ll l, r; cin >> l >> r;
        bool possible = 1;
        if (r - l >= l) {
            possible = 0;
        }
        cout << (possible ? "YES\n" : "NO\n");
    }
    return 0;
}