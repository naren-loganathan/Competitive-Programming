#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, a, max_mex = 0, arr[101] = {};
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a;
            arr[a]++;
        }
        for(int i = 0; i < 101; i++){
            if(arr[i] == 0)
                break;
            else{
                max_mex++;
                arr[i]--;
            }
        }
        for(int i = 0; i < 101; i++){
            if(arr[i] == 0)
                break;
            else
                max_mex++;
        }
        cout << max_mex << endl;
    }
    return 0;
}