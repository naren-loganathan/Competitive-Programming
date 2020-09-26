#include <iostream>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n, moves = 0;
        cin >> n;
        while (n != 1) {
            if (n % 3 == 0) {
                if (n % 2 == 0) {
                    moves++;
                    n /= 6;
                }
                else {
                    moves += 2;
                    n /= 3;
                }
            }
            else {
                moves = -1;
                break;
            }
        }
        cout << moves << "\n";
    }
    return 0;
}