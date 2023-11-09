#include<iostream>

using namespace std;

int main(){
    int a, b , v;
    cin >> a>>b>>v;
    
    if((v-a)%(a-b)==0){
        cout << (v-a)/(a-b)+1;
    }
    else {
        cout << (v-a)/(a-b)+2;
    }
}