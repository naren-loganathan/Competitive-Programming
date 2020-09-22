#include <iostream>
#include <set>
#include <vector>
using namespace std;

typedef long long int ll;

int dp[100001] = {};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, l;
    cin >> n >> m;
    vector <int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    set <int> distincts;
    for(int i = n; i > 0; i--){
        distincts.insert(a[i]);
        dp[i] = distincts.size();
    }
    for(int i = 0; i < m; i++){
        cin >> l;
        cout << dp[l] << "\n";
    }
    return 0;
}