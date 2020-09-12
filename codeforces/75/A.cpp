#include <iostream>
#include <string>
using namespace std;

int sanzero(int x){
    string s = to_string(x);
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '0'){
            s.erase(s.begin() + i);
            i--;
        }
    }
    return stoi(s);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c;
    cin >> a >> b;
    c = a + b;
    if(sanzero(a) + sanzero(b) == sanzero(c))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}