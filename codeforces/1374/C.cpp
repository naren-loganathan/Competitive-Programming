#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    string s;
    cin >> t;
    while(t--){
        int front_count = 0, back_count = 0;
        cin >> n >> s;
        for(int i = 0; i < n; i++){
            if(s[i] == '(')
                front_count++;
            else{
                if(front_count > 0)
                    front_count--;
                else
                    back_count++;
            }
        }
        cout << back_count << endl;
    }
    return 0;
}