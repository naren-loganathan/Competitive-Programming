#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, a, extras = 0;
    vector <int> walks;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a;
        walks.push_back(a);
    }
    for(int i = 1; i < n; i++){
        if(walks[i] + walks[i - 1] < k){
            extras += k - walks[i - 1] - walks[i];
            walks[i] = k - walks[i - 1];
        }
    }
    cout << extras << "\n";
    for(int i = 0; i < n; i++)
        cout << walks[i] << " ";
    cout << endl;
    return 0;
}