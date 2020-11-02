#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long int ll;
#define fi first
#define se second
#define mp make_pair

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
       ll n, courier, pickup, pickup_sum = 0; 
       cin >> n;
       vector < pair <ll, ll> > a(n);
       vector <ll> b(n);
       for (int i = 0; i < n; i++) {
           cin >> courier;
           a[i] = mp(courier, i);
       }
       for (int i = 0; i < n; i++) {
           cin >> b[i];
       }
       sort(a.begin(), a.end());
       reverse(a.begin(), a.end());
       ll result = a[0].fi;
       for (int i = 0; i < n; i++) {
           if (pickup_sum + b[a[i].se] < a[i].fi) {
               pickup_sum += b[a[i].se];
               if (i < n - 1) {
                    result = max(a[i + 1].fi, pickup_sum);
               }
               else {
                   result = pickup_sum;
               }
           }
           else {
               break;
           }
       }
       cout << result << "\n";
    }
    return 0;
}