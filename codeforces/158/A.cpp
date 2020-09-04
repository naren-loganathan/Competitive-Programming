#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, qualifying_score = 0;
    cin >> n >> k;
    int arr[n], num_advanced = k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    qualifying_score = arr[k - 1];
    if(qualifying_score != 0){
        for(int i = k; i < n; i++){
            if(arr[i] == qualifying_score)
                num_advanced++;
            else
                break;
        }
    }
    else{
        for(int i = k - 1; i >= 0; i--){
            if (arr[i] == 0)
                num_advanced--;
            else
                break;
        }
    }
    cout << num_advanced << endl;
    return 0;
}