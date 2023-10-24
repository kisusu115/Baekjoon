#include <iostream>
#include <vector>
using namespace std;

int main(){
    int sum = 0;
    int v[9];
    for (int i = 0; i < 9; i++){
        cin >> v[i];
        sum += v[i];
    }

    for (int i = 0; i < 8; i++){
        bool answer = false;
        for (int j = i + 1; j < 9; j++){
            if (sum - (v[i] + v[j]) == 100){
                for (int k = 0; k < 9; k++)
                    if (k != i && k != j)
                        cout << v[k] << "\n";
                answer = true;
                break;
            }
        }
        if (answer)
            break;
    }
    return 0;
}