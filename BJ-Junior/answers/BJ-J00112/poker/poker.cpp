#include <bits/stdc++.h>
using namespace std;
int a[15][15];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int p=52;
    for(int i=1;i<=n;i++){
        char x,y;
        cin>>x>>y;
        int t;
        if(y=='A'){
            t=1;
        }
        else if(y=='T'){
            t=10;
        }
        else if(y=='Q'){
            t=12;
        }
        else if(y=='J'){
            t=11;
        }
        else if(y=='K'){
            t=13;
        }
        else{
            t=y-'0';
        }
        if(x=='C'){
           a[1][t]=1;
        }
        if(x=='D'){
            a[2][t]=1;
        }
        if(x=='H'){
            a[3][t]=1;
        }
        if(x=='S'){
            a[4][t]=1;
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==1){
                p--;
            }
        }
    }
    cout<<p;
    return 0;
}
