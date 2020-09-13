#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if(n % 2)
        cout << 0 * n << endl;
    else
        cout << (1 << n / 2) << endl;
    return 0;
}