#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    vector <int> cubes(50000);
    bool possible = 0;
    cin >> t;
    while(t--){
        possible = 0;
        cin >> n;
        cin >> cubes[0];
        for(int i = 1; i < n; i++){
            cin >> cubes[i];
            if(cubes[i - 1] <= cubes[i]){
                possible = 1;
            }
        }
        cout << (possible ? "YES\n" : "NO\n");
    }
    return 0;
}