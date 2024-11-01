#include<bits/stdc++.h>
using namespace std;
int poker[5][15];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b;
        int x,y;
        cin>>a>>b;
        if(a=='D')x=1;
        else if(a=='C')x=2;
        else if(a=='H')x=3;
        else x=4;
        if(b=='A')y=1;
        else if(b<='9'&&b>='2')y=b-'0';
        else if(b=='T')y=10;
        else if(b=='J')y=11;
        else if(b=='Q')y=12;
        else y=13;
        poker[x][y]=1;
    }
    int ans=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(poker[i][j]==0)ans++;
        }
    }
    cout<<ans;
    return 0;
}
