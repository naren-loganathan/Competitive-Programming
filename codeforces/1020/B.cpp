#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector <int> p(n + 1), count(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            count[j] = 0;
        }
        int culprit = i;
        int holes = count[i];
        while(holes != 1){
            count[culprit]++;
            culprit = p[culprit];
            holes = count[culprit];
        }
        cout << culprit << " ";
    }
    cout << endl;
    return 0;
}