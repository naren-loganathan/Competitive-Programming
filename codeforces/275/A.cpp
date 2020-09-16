#include <iostream>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int presses[3][3], lights[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            cin >> presses[i][j];
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int num_changes = presses[i][j];
            if(i > 0)
                num_changes += presses[i - 1][j];
            if(i < 2)
                num_changes += presses[i + 1][j];
            if(j > 0)
                num_changes += presses[i][j - 1];
            if(j < 2)
                num_changes += presses[i][j + 1];
            if(num_changes % 2 == 0)
                lights[i][j] = 1;
            else
                lights[i][j] = 0;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            cout << lights[i][j];
        cout << "\n";
    }
    return 0;
}