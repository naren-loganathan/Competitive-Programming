#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long long int l, r;
    cin >> l >> r;
    if(l % 2 == 0 && r - l >= 2)
        cout << l << " " << l + 1 << " " << l + 2;
    else if(l % 2 != 0 && r - l >= 3)
        cout << l + 1 << " " << l + 2 << " " << l + 3;
    else
        cout << "-1";
    cout << endl;
    return 0;
}