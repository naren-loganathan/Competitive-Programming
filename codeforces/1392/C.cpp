#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector <int> supports(n);
        ll min_op = 0;
        for(int i = 0; i < n; i++){
            cin >> supports[i];
        }
        for(int i = n - 1; i > 0; i--){
            if(supports[i] < supports[i - 1]){
                min_op += (supports[i - 1] - supports[i]);
            }
        }
        cout << min_op << "\n";
    }
    return 0;
}