#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define mp make_pair
#define ub upper_bound

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n; cin >> n;
    vector <ll> a(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << "1 1\n0\n1 1\n0\n1 1\n" << (-1) * a[1] << "\n"; 
    }
    else {
        cout << "1 1\n" << (-1) * a[1] << "\n";
        cout << "1 " << n << "\n";
        for (ll i = 1; i <= n; i++) {
            cout << (i == 1 ? 0 : (-n) * a[i]) << " ";
        }
        cout << "\n";
        cout << "2 " << n << "\n";
        for (ll i = 2; i <= n; i++) {
            cout << (n - 1) * a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}