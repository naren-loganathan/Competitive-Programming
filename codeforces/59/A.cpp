#include <iostream>
#include <string>
using namespace std;

string lowercase(string s){
    for(int i = 0; i < s.length(); i++){
        if(s[i] < 96)
            s[i] += 32;
    }
    return s;
}

string uppercase(string s){
    for(int i = 0; i < s.length(); i++){
        if(s[i] > 96)
            s[i] -= 32;
    }
    return s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num_upper = 0, num_lower = 0;
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
            if(s[i] > 96)
                num_lower++;
            else
                num_upper++;
    }
    if(num_lower >= num_upper)
        s = lowercase(s);
    else
        s = uppercase(s);
    cout << s << endl;
    return 0;
}