#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool output = 0;
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'H' || s[i] == 'Q' || s[i] == '9'){
            output = 1;
            break;
        }
    }
    if(output) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}