#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n, k, ans;
    cin >> n >> k;
    if(n % 2 == 0){
        if(k <= n / 2)
            ans = 2 * k - 1;
        else
            ans = 2 * k - n;
    }
    else{
        if(k <= n / 2 + 1)
            ans = 2 * k - 1;
        else
            ans = 2 * k - n - 1;
    }
    cout << ans << endl;
    return 0;
}