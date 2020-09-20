#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, x;
    cin >> t;
    while(t--){
        int count = 2, account, killjoy_rivals = 0;
        ll rating_sum = 0;
        cin >> n >> x;
        for(int i = 0; i < n; i++){
            cin >> account;
            if(account == x){
                killjoy_rivals++;
            }
            rating_sum += account;
        }
        if(killjoy_rivals == n){
            count = 0;
        }
        else if((rating_sum == n * x) || killjoy_rivals > 0){
            count = 1; 
        }
        cout << count << "\n";
    }
    return 0;
}