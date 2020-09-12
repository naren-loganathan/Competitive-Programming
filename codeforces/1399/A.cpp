#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, removable = 0;
        cin >> n;
        vector <int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        for(int i = 1; i < n; i++){
            if(arr[i] - arr[i - 1] < 2)
                removable++;
        }
        if(removable == n - 1)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}