#include <iostream>
#include <string>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    ll k, max_wsi = 0, f = 0, arr[26];
    cin >> s >> k;
    for(int i = 0; i < 26; i++){
        cin >> arr[i];
        if(arr[i] > max_wsi)
            max_wsi = arr[i];
    }
    for(int i = 0; i < s.length(); i++)
        f += arr[s[i] - 97] * (i + 1);
    for(int i = s.length(); i < s.length() + k; i++)
        f += max_wsi * (i + 1);
    cout << f << endl;
    return 0;
}