#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long int ll;
#define M 1000000007

ll arr[26] = {};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll max = 0, k, n;
    string s;
    cin >> n >> k;
    cin >> s;
    for(ll i = 0; i < n; i++){
        arr[s[i] - 65]++;
    }
    sort(arr, arr + 26, greater<ll>());
    for(ll i = 0; i < n; i++){
        if(arr[i] == 0){
            break;
        }
        else{
            if(arr[i] >= k){
                max += (k * k);
                break;
            }
            else{
                max += (arr[i] * arr[i]);
                k -= arr[i];
            }
        }
    }
    cout << max << endl;
    return 0;
}