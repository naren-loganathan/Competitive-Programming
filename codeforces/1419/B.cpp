#include <iostream>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    ll x;
    cin >> t;
    while(t--){
        int count = 0;
        cin >> x;
        ll n = 1, cells_used = 0;
        while(cells_used <= x){
            cells_used += n * (n + 1) / 2;
            n = 2 * (n + 1) - 1;
            count++;
        }
        cout << count - 1 << endl;
    }
    return 0;
}