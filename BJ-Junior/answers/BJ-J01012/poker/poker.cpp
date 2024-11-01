#include<bits/stdc++.h>
using namespace std;
bool dis[100][100];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b;
        cin>>a>>b;
        int type,num;
        if(b>='0'&&b<='9')num=b-'0';
        else if(b=='A')num=1;
        else if(b=='T')num=10;
        else if(b=='J')num=11;
        else if(b=='Q')num=12;
        else if(b=='K')num=13;
        if(a=='D')dis[1][num]=1;
        else if(a=='C')dis[2][num]=1;
        else if(a=='H')dis[3][num]=1;
        else if(a=='S')dis[4][num]=1;
    }
    int ans=0;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=13;j++)
            if(dis[i][j]==0)ans++;
    cout<<ans;
    return 0;
}
