#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while (t--) {
        ll s, burles_max = 0, pow_10; 
        cin >> s;
        while (s >= 10) {
            ll pow10 = 10;
            while (pow10 <= s) {
                pow10 *= 10;
            }
            pow10 /= 10;
            burles_max += pow10;
            s += (pow10 / 10 - pow10);
        }
        burles_max += s;
        cout << burles_max << "\n";
    }
    return 0;
}