#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '+')
            s.erase(i, 1);
    }
    sort(s.begin(), s.end());
    for(int i = 0; i < s.length() - 1; i += 2){
        s.insert(i + 1, "+");
    }
    cout << s << endl;
    return 0;
}