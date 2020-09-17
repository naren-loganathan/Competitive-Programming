#include <iostream>
#include <string>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    bool is_possible = 0, a_present = 0, b_present = 0;
    if(a.length() == b.length()){
        if(a == b)
            is_possible = 1;
        else{
            if(a.length() != 1){
                for(int i = 0; i < a.length(); i++){
                    if(a[i] == '1')
                        a_present = 1;
                    if(b[i] == '1')
                        b_present = 1;
                    if(a_present && b_present){
                        is_possible = 1;
                        break;
                    }
                }
            }
        }
    }
    if(is_possible)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}