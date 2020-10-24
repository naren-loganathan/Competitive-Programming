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
    //cin >> t;
    while (t--) {
        ll n, x, pos;
        cin >> n >> x >> pos;
        ll low = 0, high = n, count_low = 0, count_high = 0;
        while (low < high) {
            ll middle = (low + high) / 2;
            if (pos >= middle) {
                low = middle + 1;
                if (pos != middle) {
                    count_low++;
                }
            }
            else {
                high = middle;
                count_high++;
            }
        }
        ll ways = 1;
        if (count_low > (x - 1) || count_high > (n - x)) {
            ways = 0;
        }
        else {
            ll bleh = n - x;
            for (ll i = 0; i < count_high; i++) {
                ways = (ways * bleh) % 1000000007;
                bleh--;
            }
            bleh = x - 1;
            for (ll i = 0; i < count_low; i++) {
                ways = (ways * bleh) % 1000000007;
                bleh--;
            }
            bleh = n - count_low - count_high - 1;
            for (ll i = 1; i <= bleh; i++) {
                ways = (ways * i) % 1000000007;
            }
        }
        cout << ways << "\n";
    }
    return 0;
}