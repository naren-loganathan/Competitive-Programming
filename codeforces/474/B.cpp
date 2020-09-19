#include <iostream>
using namespace std;

#define ll long long int

int b_search(ll arr[], ll q, int n){
    int low = 1;
    int high = n;
    int mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(q > arr[mid])
            low = mid + 1;
        else if(q <= arr[mid - 1])
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
    ll q;
    cin >> n;
    ll arr[n + 1];
    arr[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> q;
        cout << b_search(arr, q, n) << "\n";
    }
    return 0;
}