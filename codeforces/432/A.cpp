#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, y, count = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> y;
        if(5 - y >= k)
            count++;
    }
    cout << count / 3 << endl;
    return 0;
}