#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s.length() > 10){
            cout << s[0] << s.length() - 2 << s[s.length() - 1] << "\n";
        }
        else
            cout << s << "\n";
    }
    return 0;
}