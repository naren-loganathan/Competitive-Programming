#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;
#define M 1000000007

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    ll score_total = 0, score = 0;
    cin >> n;
    vector <ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        score_total += a[i];
    }
    score = score_total;
    if(n > 1){
        score_total *= 2;
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n - 2; i++){
        score -= a[i];
        score_total += score;
    }
    cout << score_total << endl;
    return 0;
}