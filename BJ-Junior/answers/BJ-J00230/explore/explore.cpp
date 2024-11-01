#include<bits/stdc++.h>
using namespace std;
const int N=1e3+9;
int n,m,k,x,y,d,t,f;
char mp[N][N];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) cin>>mp[i][j];
        if(d==0){
            if(mp[x][y+1]=='.') f=1;
            else f=0;
        }
        if(d==1){
            if(mp[x+1][y]=='.') f=1;
            else f=0;
        }
        if(d==2){
            if(mp[x][y-1]=='.') f=1;
            else f=0;
        }
        if(d==3){
            if(mp[x-1][y]=='.') f=1;
            else f=0;
        }
        if(f) cout<<2<<endl;
        else cout<<1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
