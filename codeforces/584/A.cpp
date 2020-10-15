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
    int n, t;
    cin >> n >> t;
    if (t == 10 && n == 1) {
        cout << "-1\n";
    }
    else {
        string s = to_string(t);
        if (t == 10) {
            n -= 2;
        }
        else {
            n -= 1;
        }
        while (n--) {
            s += "0";
        }
        cout << s << "\n";
    }
    return 0;
}