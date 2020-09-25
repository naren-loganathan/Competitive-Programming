#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, a;
    cin >> t;
    while(t--){
        cin >> n;
        ll ans = 0;
        vector <int> hsb(32, 0); //stores position of highest significant bit
        for(int i = 0; i < n; i++){
            cin >> a;
            int position = 0;
            while((1 << position) <= a){
                position++;
            }
            hsb[position - 1]++;
        }
        for(int i = 0; i < 32; i++){
            ans += (ll) hsb[i] * (hsb[i] - 1) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}