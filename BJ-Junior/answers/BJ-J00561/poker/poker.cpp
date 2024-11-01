#include <bits/stdc++.h>
using namespace std;
int n,ans;
bool vis[5][14];//d 1 c 2 h 3 s 4
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        string s;
        cin>>s;
        int v,u;
        if(s[0]=='D')
            v=1;
        else if(s[0]=='C')
            v=2;
        else if(s[0]=='H')
            v=3;
        else
            v=4;
        if(s[1]=='A')
            u=1;
        else if(s[1]=='T')
            u=10;
        else if(s[1]=='J')
            u=11;
        else if(s[1]=='Q')
            u=12;
        else if(s[1]=='K')
            u=13;
        else
            u=s[1]-48;
        vis[v][u]=true;
    }
    for(int i = 1;i<=4;i++){
        for(int j = 1;j<=13;j++){
            if(!vis[i][j])
                ans++;
        }
    }
    cout << ans;
    return 0;
}
