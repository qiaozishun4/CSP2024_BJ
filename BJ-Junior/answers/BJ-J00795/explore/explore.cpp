#include<bits/stdc++.h>
using namespace std;
char l[1005][1005];
bool mp[1005][1005];
int T,m,n,k,x,y,d,ans;
void dfs(int x,int y,int d,int k){
    if(mp[x][y]==false){
        ans++;
        mp[x][y]=true;
    }
    if(k==0)return ;
    if(d==0){
        if(y+1>m)d=1;
        else if(l[x][y+1]=='x')d=1;
        else if(l[x][y+1]=='.')y++;
    }
    else if(d==1){
        if(x+1>n)d=2;
        else if(l[x+1][y]=='x')d=2;
        else if(l[x+1][y]=='.')x++;
    }
    else if(d==2){
        if(y-1<1)d=3;
        else if(l[x][y-1]=='x')d=3;
        else if(l[x][y-1]=='.')y--;
    }
    else if(d==3){
        if(x-1<1)d=0;
        else if(l[x-1][y]=='x')d=0;
        else if(l[x-1][y]=='.')x--;
    }
    dfs(x,y,d,k-1);
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i1=1;i1<=n;i1++){
            for(int i2=1;i2<=m;i2++){
                cin>>l[i1][i2];
                mp[i1][i2]=false;
            }
        }
        dfs(x,y,d,k);
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
