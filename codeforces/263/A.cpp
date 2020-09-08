#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[5][5], loc_i, loc_j;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> arr[i][j];
            if(arr[i][j]){
                loc_i = i; 
                loc_j = j;
            }
        }
    }
    cout << abs(loc_i - 2) + abs(loc_j - 2) << endl;
    return 0;
}