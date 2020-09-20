#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector <int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        if(arr[0] > arr[n - 1]){
            cout << "NO";
        }
        else{
            cout << "YES";
        }
        cout << endl;
    }
    return 0;
}