#include<bits/stdc++.h>
using namespace std;
char a[1000005][1000005];
int cnt=0;
void dfs(int x,int y,int k,int d){
    if(k==0)return ;
    if(d==0&&a[x][y]!='x'&&x<=n&&y<=m){
        cnt++;
        a[x][y]='x';
        return dfs(x,y+1,k-1,d);
    }else if(d==0&&a[x][y]=='x'&&x<=n&&y<=m){
        d=(d+1)%4;
        k--;
    }
    if(d==1&&a[x][y]!='x'&&x<=n&&y<=m){
        cnt++;
        a[x][y]='x';
        return dfs(x+1,y,k-1,d);
    }else if(d==1&&a[x][y]=='x'&&x<=n&&y<=m){
        d=(d+1)%4;
        k--;
    }
    if(d==2&&a[x][y]!='x'&&x<=n&&y<=m){
        cnt++;
        a[x][y]='x';
        return dfs(x,y-1,k-1,d);
    }else if(d==2&&a[x][y]=='x'&&x<=n&&y<=m){
        d=(d+1)%4;
        k--;
    }
    if(d==3&&a[x][y]!='x'&&x<=n&&y<=m){
        cnt++;
        a[x][y]='x';
        return dfs(x,y,k-1,d);
    }else if(d==3&&a[x][y]=='x'&&x<=n&&y<=m){
        d=(d+1)%4;
        k--;
    }
}
int main(){
    freopen("explore.in","r",stdin)
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)scanf("%s",a[i]);
        dfs(x,y,k,d);
        cout<<cnt<<<endl;
    }
    return 0;
}
