#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1005;
int a[N][N];
int t,n,m,k,sum;
bool check(int x,int y){
    return x>=1&&x<=n&&y>=1&&y<=m;
}
void dfs(int x,int y,int d){
    sum++;
    if(sum==k+1) return;
    if(d==0){
        if(check(x,y+1)&&a[x][y+1]!=1){
            dfs(x,y+1,d);
            a[x][y+1]=3;
        }
        else dfs(x,y,(d+1)%4);
    }
    if(d==1){
        if(check(x+1,y)&&a[x+1][y]!=1){
            dfs(x+1,y,d);
            a[x+1][y]=3;
        }
        else dfs(x,y,(d+1)%4);
    }
    if(d==2){
        if(check(x,y-1)&&a[x][y-1]!=1){
            dfs(x,y-1,d);
            a[x][y-1]=3;
        }
        else dfs(x,y,(d+1)%4);
    }
    if(d==3){
        if(check(x-1,y)&&a[x-1][y]!=1){
            dfs(x-1,y,d);
            a[x-1][y]=3;
        }
        else dfs(x,y,(d+1)%4);
    }
}
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        sum=0;
        cin>>n>>m>>k;
        int xx,yy,dd;
        cin>>xx>>yy>>dd;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            for(int j=0;j<s.size();j++){
                if(s[j]=='.') a[i][j+1]=0;
                else a[i][j+1]=1;
            }
        }
        int ans=0;
        a[xx][yy]=3;
        dfs(xx,yy,dd);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]==3) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
