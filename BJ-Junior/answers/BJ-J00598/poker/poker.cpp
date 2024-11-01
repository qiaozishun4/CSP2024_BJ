#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int b[5][14];
int main(){

    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x=0,y=0;
        char tmp1,tmp2;
        cin>>tmp1>>tmp2;
        if(tmp1=='D') x=1;
        else if(tmp1=='C') x=2;
        else if(tmp1=='H') x=3;
        else x=4;
        if(tmp2=='A') y=1;
        else if(tmp2=='T') y=10;
        else if(tmp2=='J') y=11;
        else if(tmp2=='Q') y=12;
        else if(tmp2=='K') y=13;
        else{
            y=tmp2-'0';
        }
        b[x][y]++;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++) if(b[i][j]==0) cnt++;
    }
    cout<<cnt;
    return 0;

}
