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
        int a, b, c, d, boxes[4] = {1, 1, 1, 1};
        cin >> a >> b >> c >> d;
        if ((a + b) % 2 == 0) {
            boxes[0] = 0; boxes[1] = 0;
        }
        else {
            boxes[2] = 0; boxes[3] = 0;
        }
        if (b + c == 0) {
            boxes[1] = 0; boxes[2] = 0;
        }
        if (a + d == 0) {
            boxes[0] = 0; boxes[3] = 0;
        }  
        for (int i = 0; i < 4; i++) {
            cout << (boxes[i] ? "Ya " : "Tidak ");
        }
        cout << "\n";
    }
    return 0;
}