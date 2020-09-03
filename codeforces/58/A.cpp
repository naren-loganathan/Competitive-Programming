#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    string msg = "hello";
    int k = 0, j = 0;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(k == j && s[i] == msg[j]){
            j++;
            k++;
        }
    }
    if(k == msg.length())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}