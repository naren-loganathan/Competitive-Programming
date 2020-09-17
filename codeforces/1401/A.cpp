#include <iostream>
#include <cmath>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k, minsteps = 0;
        cin >> n >> k;
        if(k > n)
            minsteps = k - n;
        if((n - k) % 2 && k < n)
            minsteps = 1;
        cout << minsteps << "\n";
    }
    return 0;
}