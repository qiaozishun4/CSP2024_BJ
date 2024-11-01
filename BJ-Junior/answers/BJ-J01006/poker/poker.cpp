#include<bits/stdc++.h>
using namespace std;
bool vis[4][13];
int n,cnt;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        char a,b;
        int x,y;
        cin>>a>>b;
        if(a=='D')x=0;
        else if(a=='C')x=1;
        else if(a=='H')x=2;
        else x=3;
        if(b=='A')y=0;
        else if(b=='T')y=9;
        else if(b=='J')y=10;
        else if(b=='Q')y=11;
        else if(b=='K')y=12;
        else y=b-1-'0';
        vis[x][y]=1;
    }
    for(int i=0;i<4;i++)
        for(int j=0;j<13;j++)
            if(!vis[i][j])
                cnt++;
    cout<<cnt<<'\n';
    return 0;
}
