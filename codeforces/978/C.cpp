#include <iostream>
using namespace std;

#define ll long long int

ll arr[200001] = {};

int b_search(ll a, ll arr[], int n){
    int low = 1;
    int high = n;
    int mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(a > arr[mid])
            low = mid + 1;
        else if(a <= arr[mid - 1])
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    ll b;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    for(int i = 0; i < m; i++){
        cin >> b;
        int f = b_search(b, arr, n);
        ll k = b - arr[f - 1];
        cout << f << " " << k << "\n";
    }
    return 0;
}