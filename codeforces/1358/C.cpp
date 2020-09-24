#include <iostream>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    ll x1, y1, x2, y2;
    cin >> t;
    while(t--){
        cin >> x1 >> y1 >> x2 >> y2;
        ll ans = (x2 - x1) * (y2 - y1) + 1;
        cout << ans << "\n";
    }
    return 0;
}