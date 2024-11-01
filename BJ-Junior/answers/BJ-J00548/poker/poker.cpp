#include<bits/stdc++.h>
using namespace std;
int n, cnt;
bool a[4][14];
int cn(char a){
    if(a == 'A') return 1;
    if(a == 'T') return 10;
    if(a == 'J') return 11;
    if(a == 'Q') return 12;
    if(a == 'K') return 13;
    return a - '0';
}
int tn(char c){
    if(c == 'D') return 0;
    if(c == 'C') return 1;
    if(c == 'H') return 2;
    if(c == 'S') return 3;
}
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin>>n;
    while(n--){
        char x, y;
        cin>>x>>y;
        a[tn(x)][cn(y)] = true;
    }
    for(int i = 0; i < 4; i++){
        for(int j = 1; j <= 13; j++){
            if(!a[i][j]) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
