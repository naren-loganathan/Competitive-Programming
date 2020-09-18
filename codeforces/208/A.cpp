#include <iostream>
#include <string>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int count = 0;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(i < s.length() - 2 && s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B'){
            i += 2;
            if(count != 0)
                cout << " ";
            count = 0;
        }
        else{
            cout << s[i];
            count = 1;
        }
    }
    cout << endl;
    return 0;
}