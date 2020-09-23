#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long int ll;
#define M 1000000007

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, d;
    bool possible = 1;
    cin >> n >> m >> d;
    ll arr[n * m], sum = 0;
    for(int i = 0; i < n * m; i++){
        cin >> arr[i];
    }
    int a = arr[0] % d;
    for(int i = 0; i < n * m; i++){
        if(arr[i] % d != a){
            possible = 0;
            break;
        }
    }
    if(possible){
        sort(arr, arr + (n * m));
        int min_moves = 0;
        for(int i = 0; i < n * m; i++){
            min_moves += abs(arr[n * m / 2] - arr[i]) / d;
        }
        cout << min_moves << "\n";
    }
    else{
        cout << "-1\n";
    }
    return 0;
}