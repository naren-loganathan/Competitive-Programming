#include <iostream>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, n, w;
    cin >> k >> n >> w;
    if (w * (w + 1) * k / 2 > n) {
        cout << w * (w + 1) * k / 2 - n << endl;
    }
    else {
        cout << "0\n";
    }
    return 0;
}