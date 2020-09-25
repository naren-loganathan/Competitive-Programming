#include <iostream>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l, r;
    cin >> l >> r;
    if (l == r) {
         cout << l << endl;
    } else {
        cout << "2" << endl;
    }
    return 0;
}