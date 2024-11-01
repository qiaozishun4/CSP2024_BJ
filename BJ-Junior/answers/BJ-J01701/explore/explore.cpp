#include<bits/stdc++.h>
using namespace std;
int n,m,t,k,x,y,d,ans,v[1005][1005];
char a[1005][1005];
void f(){
    int nx=d==1?x+1:d==3?x-1:x;
    int ny=d==0?y+1:d==2?y-1:y;
    if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]=='x'){
        d=(d+1)%4;
    }
    else{
        x=nx,y=ny;
        if(!v[x][y])ans++;
        v[x][y]=1;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        memset(v,0,sizeof(v));
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i]+1;
        }
        ans=1;
        v[x][y]=1;
        while(k--){
            f();
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
