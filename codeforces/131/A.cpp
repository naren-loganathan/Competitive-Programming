#include <iostream>
#include <string>
using namespace std;

void capsLock(string s){
    for(int i = 0; i < s.length(); i++){
        if(s[i] < 97)
            s[i] += 32;
        else
            s[i] -= 32;
    }
    cout << s << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool capslock_on = 1;
    string s;
    cin >> s;
    for(int i = 1; i < s.length(); i++){
        if(s[i] > 96){
            capslock_on = 0;
            break;
        }
    }
    if(capslock_on)
        capsLock(s);
    else
        cout << s << endl;
    return 0;
}