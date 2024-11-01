#include<bits/stdc++.h>
using namespace std;
int n,m,aa[5002],c[5002],x[5],r[5002];
int t,a[5002],d[5002][5002],q[5002];
int dfs(int x,int y){
    if(x==1) return r[1];
    for(int i=1,v=1;i<=x+1;i+=2,v++){
        if(d[y][v]){
            if(a[r[i+1]]>=v) q[v]=i+1,r[v]=r[i+1];
            else q[v]=i,r[v]=r[i];
        }else{
            if(a[r[i]]>=v) q[v]=i,r[v]=r[i];
            else q[v]=i+1,r[v]=r[i+1];
        }
    }
    return dfs(x/2,y+1);
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>aa[i];
    for(int i=1;i<=m;i++) cin>>c[i];
    int ans=1,k=0;
    while(ans<n) ans*=2,k++;
    for(int i=1;i<=k;i++){
        ans/=2;
        string s;
        cin>>s;
        for(int j=1;j<=ans;j++){
            d[i][j]=s[j-1]-'0';
        }
    }
    cin>>t;
    while(t--){
        for(int i=0;i<4;i++) cin>>x[i];
        for(int i=1;i<=n;i++){
            a[i]=aa[i]^x[(i%4)];
        }
        int cnt=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=c[i];j++) q[j]=r[j]=j;
            cnt^=(i*dfs(c[i],1));
        }
        cout<<cnt<<endl;
    }
    return 0;
}
