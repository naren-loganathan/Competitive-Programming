#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    long long int n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        if((n + k) % 2 == 0 && k * k <= n)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";   
    }
    return 0;
}