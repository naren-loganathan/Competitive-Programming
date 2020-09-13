#include <iostream>
#include <cmath>
using namespace std;

long long int dp[100001], arr[100001] = {};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        arr[a]++;
    }
    dp[0] = 0;
    dp[1] = arr[1];
    for(int i = 2; i < 100001; i++)
        dp[i] = max(i * arr[i] + dp[i - 2], dp[i - 1]);
    cout << dp[100000] << endl;
    return 0;
}