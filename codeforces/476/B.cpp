#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

typedef long long int ll;

double factorial(int n){
    if(n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

double combinations(int n, int r){
    return factorial(n) / (factorial(n - r) * factorial(r));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num_questions = 0, distance = 0;
    long double probability;
    string drazil, dreamoon;
    cin >> drazil >> dreamoon;
    for(int i = 0; i < drazil.length(); i++){
        if(drazil[i] == '+')
            distance++;
        else
            distance--;
        if(dreamoon[i] == '-')
            distance++;
        else if(dreamoon[i] == '+')
            distance--;
        if(dreamoon[i] == '?')
            num_questions++;
    }
    distance = abs(distance);
    if(num_questions < distance || (num_questions + distance) % 2 != 0)
        probability = 0;
    else
        probability = combinations(num_questions, (num_questions + distance) / 2) / (1 << num_questions);
    cout << fixed << setprecision(12) << probability << endl;
    return 0;
}