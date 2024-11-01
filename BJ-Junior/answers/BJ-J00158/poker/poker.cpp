#include<iostream>
 using namespace std;
 int a[5][20];
 int main(){
     freopen("poker.in","r",stdin);
     freopen("poker.out","w",stdout);
     int n;
     cin>>n;
     int x,y;
     char c1,c2;
     for(int i=1;i<=n;i++){
        cin>>c1>>c2;
        if(c1=='D') x=1;
        if(c1=='C') x=2;
        if(c1=='S') x=3;
        if(c1=='H') x=4;
        if(c2=='A') y=1;
        else if(c2=='T') y=10;
        else if(c2=='J') y=11;
        else if(c2=='Q') y=12;
        else if(c2=='K') y=13;
        else y=c2-'0';
        a[x][y]++;
     }
     int ans=0;
     for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++) if(a[i][j]==0) ans++;
     }
     printf("%d\n",ans);
     return 0;
 }
