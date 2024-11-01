#include<bits/stdc++.h>
using namespace std;
bool poke[13][4];
int sum=0;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,xx=0,yy=0;
    char x,y;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        if(x=='C') xx=0;
        if(x=='S') xx=1;
        if(x=='H') xx=2;
        if(x=='D') xx=3;
        if(y=='A') yy=0;
        else if(y=='T') yy=9;
        else if(y=='J') yy=10;
        else if(y=='Q') yy=11;
        else if(y=='K') yy=12;
        else yy=y-'0'-1;
        poke[yy][xx]=1;

    }
    for(int i=0;i<13;i++){
        for(int j=0;j<4;j++){
            if(poke[i][j]!=1) sum++;
        }
    }
    cout<<sum;
    return 0;
}
