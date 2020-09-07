#include <iostream>
using namespace std;

int dp[4001] = {};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, surety, problems_attempted = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        surety = 0;
        for(int j = 0; j < 3; j++){
            cin >> a;
            surety += a;
        }
        if(surety >= 2)
            problems_attempted++;
    }
    cout << problems_attempted << endl;
    return 0;
}