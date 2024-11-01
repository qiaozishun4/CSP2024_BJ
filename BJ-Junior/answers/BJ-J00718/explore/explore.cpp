#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T,n,m,k,x,y,d,fx,fy;
char ch[N][N];
int main() {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        int ans=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>ch[i][j];
        if(ch[x][y]=='x'){
            cout<<0;
            continue;
        }
        while(x!=n && y!=m){
            ans++;
            if(ch[x+1][y]=='.') x+=1;
            else if(ch[x-1][y]=='.') x-=1;
            else if(ch[x][y+1]=='.') y+=1;
            else if(ch[x][y-1]=='.') y-=1;
        }
        cout<<ans;
    }
    return 0;
}
