#include<bits/stdc++.h>
using namespace std;
int T. n;
int s[12] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin>>T;
    while(T--){
        cin>>n;
        int minx = 1e9, ans = 0;
        if(n < 2){
            cout<<-1<<endl;
            continue;
        }
        if(n == 2){
            cout<<1<<endl;
            continue;
        }
        if(n == 3){
            cout<<7<<endl;
            continue;
        }

    }
    return 0;
}