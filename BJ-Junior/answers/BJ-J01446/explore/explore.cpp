#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,x,y,d;
string a;
char b[1005][1005];
long long v[1005][1005];
long long s=0;
int dfs(long long x,long long y,long long s){
    if(x==n&&y==m){
        return 0;
    }
        int xx=x,yy=y;
        if(d%4==0)yy=y+1;
        if(d%4==1)xx=x+1;
        if(d%4==2)yy=y-1;
        if(d%4==3)xx=x-1;
        if(xx<=n&&xx>=1&&yy>=1&&yy<=n&&v[xx][yy]==0&&b[xx][yy]=='.'){
            s++;
            v[xx][yy]=1;
            cout<<xx<<yy<<endl;
            dfs(xx,yy,s);
            v[xx][yy]=0;
        }
        else {
            d=(d+1)%4;
        }
    }

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            cin>>a;
            for(int j=1;j<=m;j++){
                b[i][j]=a[j];
            }
        }
        dfs(x,y,s);
        cout<<s<<endl;
        s=0;
    }
    return 0;
}
