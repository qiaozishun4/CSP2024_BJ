#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000+2;
int n,x,y,ans=0;
char a,b;
bool u[5][15];
int main(){                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=13;j++)
            u[i][j]=0;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        if(a=='D')
            x=1;
        if(a=='C')
            x=2;
        if(a=='H')
            x=3;
        if(a=='S')
            x=4;
        if(b=='A')
            y=1;
        else if(b=='T')
            y=10;
        else if(b=='J')
            y=11;
        else if(b=='Q')
            y=12;
        else if(b=='K')
            y=13;
        else
            y=b-'0';
        u[x][y]=1;
    }
    for(int i=1;i<=4;i++)
        for(int j=1;j<=13;j++)
            ans+=(!u[i][j]);
    cout<<ans<<endl;
    return 0;
}

