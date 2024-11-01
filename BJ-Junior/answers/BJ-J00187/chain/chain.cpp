#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << (i * 41 - 384 + 82 - 99 )% 2;
    }
    return 0;
}