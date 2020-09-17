#include <iostream>
#include <string>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string input, output;
    cin >> input;
    for(int i = 0; i < input.length(); i++){
        if(input[i] == '.')
            output.append("0");
        if(input[i] == '-'){
            if(input[i + 1] == '.')
                output.append("1");
            else
                output.append("2");
            i++;
        }
    }
    cout << output << endl;
    return 0;
}