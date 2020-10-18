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
    int arr[26] = {};
    int n; cin >> n;
    string s; cin >> s;
    if (n > 26) {
        cout << "-1\n";
    }
    else {
        int min = 0;
        for (int i = 0; i < n; i++) {
            arr[s[i] - 97]++;
        }
        for (int i = 0; i < 26; i++) {
            if (arr[i] > 1) {
                min += (arr[i] - 1);
            }
        }
        cout << min << "\n";
    }
    return 0;
}