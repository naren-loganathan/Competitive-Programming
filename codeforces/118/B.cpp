#include <iostream>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int max_row = -1;
    for(int i = 0; i <= 2 * n; i++) {
        (i > n ? max_row-- : max_row++);
        for(int j = 0; j < n - max_row; j++) {
            cout << "  ";
        }
        int max = -1;
        for(int l = 0; l <= 2 * max_row; l++) {
            (l > max_row ? max-- : max++);
            if(l != 2 * max_row) {
                cout << max << " ";
            }
            else {
                cout << max;
            }
        }
        cout << "\n";
    }
    return 0;
}