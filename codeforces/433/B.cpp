#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int arr[100001] = {}, prefix_arr[100001] = {};
    int type, l, r, n, m;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        prefix_arr[i] = arr[i] + prefix_arr[i - 1];
    }
    sort(arr, arr + n + 1);
    for(int i = 1; i <= n; i++)
        arr[i] += arr[i - 1]; 
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> type >> l >> r;
        if(type == 1)
            cout << prefix_arr[r] - prefix_arr[l - 1] << "\n";
        else
            cout << arr[r] - arr[l - 1] << "\n"; 
    }
    return 0;
}