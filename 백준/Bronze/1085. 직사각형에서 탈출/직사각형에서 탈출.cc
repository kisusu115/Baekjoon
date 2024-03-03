#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int x,y,a,b;
    cin >> x >> y >> a >>b;
    int mini = 0;
    mini = min(x, y);
    mini = min(mini, a-x);
    mini = min(mini, b-y);
    
    cout << mini;
}