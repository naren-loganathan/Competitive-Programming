#include <iostream>
#include <string>
#include <cmath>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; string s;
    int count_1 = 0, count_0 = 0;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            count_1++;
        }
        else {
            count_0++;
        }
    }
    cout << s.length() - 2 * min(count_0, count_1) << endl;
    return 0;
}