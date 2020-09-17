#include <iostream>
#include <set>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set <int> digits;
    int y;
    cin >> y;
    for(int i = y + 1; i < 9015; i++){
        int a = i;
        while(a > 0){
            digits.insert(a % 10);
            a /= 10;
        }
        if(digits.size() == 4){
            cout << i << endl;
            break;
        }
        else
            digits.clear();
    }
    return 0;
}