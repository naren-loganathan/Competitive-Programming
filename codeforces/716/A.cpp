#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, c, num_words = 1, t_prev, t_now;
    cin >> n >> c;
    cin >> t_prev;
    for(int i = 1; i < n; i++){
        cin >> t_now;
        if(t_now - t_prev > c)
            num_words = 1;
        else
            num_words++;
        t_prev = t_now;
    }
    cout << num_words << endl;
    return 0;
}