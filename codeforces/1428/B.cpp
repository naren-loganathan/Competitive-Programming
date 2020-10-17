#include <iostream>
#include <string>
using namespace std;
     
typedef long long int ll;
#define M 1000000007
#define mp make_pair
#define ub upper_bound
     
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        string s; cin >> s;
        ll returnable = n, clockwise = 0, anticlockwise = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '>') {
                clockwise++;
            }
            if (s[i] == '<') {
                anticlockwise++;
            }
        }
        if (clockwise != 0 && anticlockwise != 0) {
            for (int i = 0; i < n; i++) {
                if (s[i] != '-' && s[(i + 1) % n] != '-') {
                    returnable--;
                }
            }
        }
        cout << returnable << " ";
    }
    cout << endl;
    return 0;
}