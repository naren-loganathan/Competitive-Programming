#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

typedef long long int ll;
#define M 1000000007

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    int lucky_digits = 0;
    bool nearly_lucky = 0;
    cin >> n;
    string s = to_string(n);
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 52 || s[i] == 55){
            lucky_digits++;
        }
    }
    if(lucky_digits == 4 || lucky_digits == 7){
        nearly_lucky = 1;
    }
    cout << (nearly_lucky ? "YES\n" : "NO\n");
    return 0;
}