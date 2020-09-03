#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        switch(s[i]){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'y':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            case 'Y':
                s.erase(s.begin() + i);
                i--;
        }
    }
    for(int i = 0; i < s.length(); i += 2){
        s.insert(i, ".");
        if(s[i + 1] < 97){
            s[i + 1] += 32;
        }
    }
    cout << s << endl;
    return 0;
}