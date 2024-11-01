#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,d,ans;
short b[1007][1007]={0};
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void solve(){
    cin>>n>>m>>k>>x>>y>>d;
    ans=1;
    char c;
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>c;
            if(c=='.')b[i][j]=1;
        }
    }
    while(k>0){
        for(int i=d;k>0;i=(i+1)%4,k--){
            if(b[x+dx[i]][y+dy[i]]!=0){
                if(b[x][y]!=-1)ans++;
                b[x][y]=-1;
                x=x+dx[i],y=y+dy[i];
                break;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
