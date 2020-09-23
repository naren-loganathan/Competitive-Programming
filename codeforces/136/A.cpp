#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
#define M 1000000007

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n;
    vector <int> gifts(n);
    for(int i = 1; i <= n; i++){
        cin >> x;
        gifts[x - 1] = i;
    }
    for(int i = 0; i < n; i++){
        cout << gifts[i] << ' ';
    }
    cout << endl;
    return 0;
}