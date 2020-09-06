#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[4001] = {};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, lengths[3];
    vector <int> v;
    cin >> n >> lengths[0] >> lengths[1] >> lengths[2];
    sort(lengths, lengths + 3);
    for(int i = 0; i < 3; i++){
        int j = 0;
        while(j <= i){
            if(lengths[i] % lengths[j] == 0){
                dp[lengths[i]] = lengths[i] / lengths[j];
                break;
            }
            j++;
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; (j < 3 && lengths[j] < i); j++){
            if(dp[i - lengths[j]])
                v.push_back(dp[i - lengths[j]]);
        }
        sort(v.begin(), v.end());
        if(v.size() > 0){
            dp[i] = v[v.size() - 1] + 1;
            v.clear();
        }
    }
    cout << dp[n] << "\n";
    return 0;
}