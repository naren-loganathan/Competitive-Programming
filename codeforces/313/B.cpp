#include <iostream>
#include <string>
using namespace std;

int dp[100001] = {};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, l, r;
    string s;
    cin >> s;
    for(int i = 1; i < s.length(); i++){
        dp[i] = dp[i - 1];
        if(s[i] == s[i - 1])
            dp[i]++;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> l >> r;
        cout << dp[r - 1] - dp[l - 1] << "\n";
    }
    return 0;
}