#include <iostream>
#include <string>
using namespace std;

typedef long long int ll;
#define M 1000000007

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < s1.length(); i++){
        if(s1[i] != s2[i]){
            s1[i] = '1';
        }
        else{
            s1[i] = '0';
        }
    }
    cout << s1 << endl;
    return 0;
}