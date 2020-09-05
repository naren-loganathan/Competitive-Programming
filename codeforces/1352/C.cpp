#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, k, ans;
    cin >> t;
    while(t--){
        cin >> n >> k;
        ans = (k / (n - 1)) * n;
        k %= n - 1;
        ans += k;
        if(ans % n == 0)
            ans--;
        cout << ans << endl;
    }
    return 0;
}