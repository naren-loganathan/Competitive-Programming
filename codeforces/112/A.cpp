#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1, s2;
    int less = 0;
    cin >> s1 >> s2;
    for(int i = 0; i < s1.length(); i++){
        if(s1[i] < 97)
            s1[i] += 32;
        if(s2[i] < 97)
            s2[i] += 32;
    }
    for(int i = 0; i < s1.length(); i++){
        if(s1[i] > s2[i]){
            less = 1;
            break;
        }
        if(s1[i] < s2[i]){
            less = -1;
            break;
        }
    }
    cout << less << endl;
    return 0;
}