#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int x,y,d;
char a[1005][1005];
bool b[1005][1005];
int ans=0;
void dfs(int t,int X,int Y,int D){
    b[X][Y]=1;
    if(t==k){
        return ;
    }
    if(D==0){
        if(a[X][Y+1]=='.'){
            dfs(t+1,X,Y+1,D);
        }
        else{
            D=(D+1)%4;
        }
    }
    if(D==1){
        if(a[X+1][Y]=='.'){
            dfs(t+1,X+1,Y,D);
        }
        else{
            D=(D+1)%4;
        }
    }
    if(D==2){
        if(a[X][Y-1]=='.'){
            dfs(t+1,X,Y-1,D);
        }
        else{
            D=(D+1)%4;
        }
    }
    if(D==3){
        if(a[X-1][Y]=='.'){
            dfs(t+1,X-1,Y,D);
        }
        else{
            D=(D+1)%4;
        }
    }
    if(D==0){
        if(a[X][Y+1]=='.'){
            dfs(t+1,X,Y+1,D);
        }
        else{
            D=(D+1)%4;
        }
    }
    return ;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        memset(b,0,sizeof(b));
        memset(a,0,sizeof(a));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            for(int j=1;j<=m;j++){
                a[i][j]=s[j];
            }
        }
        ans=0;
        dfs(1,x,y,d);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(b[i][j]==1){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}