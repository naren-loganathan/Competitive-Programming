#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int times = 0, n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        if(x % i == 0 && x / i <= n)
                times++;
    }
    cout << times << endl;
    return 0;
}