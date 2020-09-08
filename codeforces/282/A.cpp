#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, num_plus = 0, num_minus = 0;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '+'){
                num_plus++;
                break;
            }
            if(s[i] == '-'){
                num_minus++;
                break;
            }
        }
    }
    cout << num_plus - num_minus << endl;
    return 0;
}