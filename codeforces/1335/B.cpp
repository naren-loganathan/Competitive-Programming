#include <iostream>
#include <string>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        for (int i = 0; i < b; i++) {
            s.pb(char (97 + i));
        }
        for(int i = b; i < a; i++) {
            s.pb(s[b - 1]);
        }
        for(int i = a; i < n; i++) {
            if((i + 1) % a != 0) {
                s.pb(s[((i + 1) % a) - 1]);
            }
            else {
                s.pb(s[b - 1]);
            }
        }
        cout << s << "\n";
    }
    return 0;
}