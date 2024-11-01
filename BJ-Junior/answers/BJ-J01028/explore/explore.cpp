#include<bits/stdc++.h>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool v[1001][1001]={};
char c[1001][1001];
long long n,m,k,x,y,d,ans=0,s=0,q,w;
void dfs(long long x,long long y,long long d){
    v[x][y]=1;
    s++;
    int q=x+dx[d];
    int w=y+dy[d];
    cout<<x<<y<<q<<w<<d<<s<<endl;
    if(q<1||q>n||w<1||w>m||v[q][w]==1||c[q][w]!='.'){
        d=(d+1)%4;
        dfs(x,y,d);
    }else{
        ans++;
        dfs(q,w,d);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long t;
    cin>>t;
    while(t!=0){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c[i][j];
            }
        }
        dfs(x,y,d);
        ans=0;
        s=0;
        t--;
    }
    return 0;
}