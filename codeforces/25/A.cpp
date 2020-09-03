#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, odd = 0, even = 0, a, odd_index, even_index;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a;
        if(a % 2 == 0){
            even++;
            even_index = i;
        }
        else{
            odd++;
            odd_index = i;
        }
    }
    if(odd == 1)
        cout << odd_index << endl;
    else
        cout << even_index << endl;
    return 0;
}