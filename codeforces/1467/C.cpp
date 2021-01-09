#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n1, n2, n3, sum1 = 0, sum2 = 0, sum3 = 0, min1 = 1e9, min2 = 1e9, min3 = 1e9;
    cin >> n1 >> n2 >> n3;
    vector <ll> a1(n1), a2(n2), a3(n3);
    for (int i = 0; i < n1; i++) {
        cin >> a1[i]; sum1 += a1[i];
        min1 = min(min1, a1[i]);
    }
    for (int i = 0; i < n2; i++) {
        cin >> a2[i]; sum2 += a2[i];
        min2 = min(min2, a2[i]);
    }
    for (int i = 0; i < n3; i++) {
        cin >> a3[i]; sum3 += a3[i];
        min3 = min(min3, a3[i]);
    }
    ll one = min(sum1, min(sum2, sum3));
    ll two = min(min1 + min2, min(min2 + min3, min3 + min1));
    cout << sum1 + sum2 + sum3 - 2 * min(one, two) << "\n";
    return 0;
}