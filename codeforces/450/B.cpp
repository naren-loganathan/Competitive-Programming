#include <iostream>
using namespace std;

typedef long long int ll;
#define M 1000000007

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y, n, ans;
    cin >> x >> y >> n;
    switch(n % 6){
        case 0:
            ans = x - y;
            break;
        case 1:
            ans = x;
            break;
        case 2:
            ans = y;
            break;
        case 3:
            ans = y - x;
            break;
        case 4:
            ans = -x;
            break;
        case 5:
            ans = -y;
            break;
    }
    if(ans < 0){
        cout << ((ans % M) + M) % M << endl;
    }
    else{
        cout << (ans % M) << endl;
    }
    return 0;
}