#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll a, max = 1;
        int n;
        cin >> n;
        ll arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n);
        for(int i = n - 1; i > n - 6; i--){
            max *= arr[i];
            a = max;
        }
        a = arr[n - 1] * arr[n - 2] * arr[n - 3] * arr[0] * arr[1];
        if(a > max)
            max = a;
        a = arr[n - 1] * arr[0] * arr[1] * arr[2] * arr[3];
        if(a > max)
            max = a;
        cout << max << "\n";
    }
    return 0;
}