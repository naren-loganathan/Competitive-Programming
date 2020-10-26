#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define N 100005
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; 
    //cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int a = 0, d = 0;
        for (int i = 0; i < s.length(); i++) {
            (s[i] == 'A' ? a++ : d++);
        }
        if (a > d) {
            cout << "Anton\n";
        }
        else if (a < d) {
            cout << "Danik\n";
        }
        else {
            cout << "Friendship\n";
        }
    }
    return 0;
}