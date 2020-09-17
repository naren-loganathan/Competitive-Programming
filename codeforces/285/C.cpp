#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll min_moves = 0;
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    for(int i = 0; i < n; i++)
        min_moves += abs(arr[i] - (i + 1));
    cout << min_moves << endl;
    return 0;
}