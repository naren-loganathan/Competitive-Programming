#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool dangerous = 0;
    int zero_count = 0, ones_count = 0;
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1'){
            zero_count = 0;
            ones_count++;
            if(ones_count >= 7){
                dangerous = 1;
                break;
            }
        }
        else{
            ones_count = 0;
            zero_count++;
            if(zero_count >= 7){
                dangerous = 1;
                break;
            }
        }
    }
    if(dangerous)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}