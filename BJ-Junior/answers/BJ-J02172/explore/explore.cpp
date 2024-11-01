#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,cnt;
bool a[1005][1005];
char s[1005][1005];
bool f(int x,int y){
    if(x<1||x>n||y<1||y>m||s[x][y]=='x')
        return 0;
    return 1;
}
void dfs(int x,int y,int d,int t){
    if(t>k)return;
    a[x][y]=1;
    if(d==0){
        if(f(x,y+1))dfs(x,y+1,d,t+1);
        else dfs(x,y,(d+1)%4,t+1);
    }
    else if(d==1){
        if(f(x+1,y))dfs(x+1,y,d,t+1);
        else dfs(x,y,(d+1)%4,t+1);
    }
    else if(d==2){
        if(f(x,y-1))dfs(x,y-1,d,t+1);
        else dfs(x,y,(d+1)%4,t+1);
    }
    else if(d==3){
        if(f(x-1,y))dfs(x-1,y,d,t+1);
        else dfs(x,y,(d+1)%4,t+1);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                a[i][j]=0;
                cin>>s[i][j];
            }
        cnt=0;
        dfs(x,y,d,0);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(a[i][j]==1)cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}
