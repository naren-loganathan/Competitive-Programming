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
    cin >> t;
    while (t--) {
        int n; cin >> n;
        float count = 0;
        string s; cin >> s;
        bool done = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                done = 0;
                count += 1;
            }
        }
        if (done) {
            cout << count << "\n";
        }
        else {
            cout << ceil(count / 2) << "\n";
        }
    }
    return 0;
}