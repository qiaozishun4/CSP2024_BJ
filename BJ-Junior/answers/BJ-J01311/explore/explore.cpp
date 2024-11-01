#include<bits/stdc++.h>
using namespace std;
char a[1001][1001];
bool flag=false;
int f[1001][1001];
int t,n,m,k,x,y,d,sum=0;
void dfs(int x,int y,int d,int k){
    if(k<0) flag=true;
    if(flag) return;
    else if(a[x][y]=='.'){
            if(f[x][y]!=1) sum++;
            f[x][y]=1;
    }
    else if(x<1 || x>n || y<1 || y>m){
            d=(d+1)%4;
            k--;
            return;
    }
    else if(a[x][y]=='x'){
            d=(d+1)%4;
            k--;
            return;
    }
    if(d==0){
        if(d==0 && a[x][y+1]=='.') dfs(x,y+1,d,--k);
    else{
        k--;
        d=(d+1)%4;
    }
    if(d==1 && a[x+1][y]=='.') dfs(x+1,y,d,--k);
    else{
        k--;
        d=(d+1)%4;
    }
    if(d==2 && a[x][y-1]=='.') dfs(x,y-1,d,--k);
    else{
        k--;
        d=(d+1)%4;
    }
    if(d==3 && a[x-1][y]=='.') dfs(x-1,y,d,--k);
    else{
        k--;
        d=(d+1)%4;
    }
    }
    if(d==1){
            if(d==1 && a[x+1][y]=='.') dfs(x+1,y,d,--k);
    else{
        k--;
        d=(d+1)%4;
    }


    if(d==2 && a[x][y-1]=='.') dfs(x,y-1,d,--k);
    else{
        k--;
        d=(d+1)%4;
    }
    if(d==3 && a[x-1][y]=='.') dfs(x-1,y,d,--k);
    else{
        k--;
        d=(d+1)%4;
    }if(d==0 && a[x][y+1]=='.') dfs(x,y+1,d,--k);
    else{
        k--;
        d=(d+1)%4;
    }
    }
    if(d==2){

    if(d==2 && a[x][y-1]=='.') dfs(x,y-1,d,--k);
    else{
        k--;
        d=(d+1)%4;
    }
    if(d==3 && a[x-1][y]=='.') dfs(x-1,y,d,--k);
    else{
        k--;
        d=(d+1)%4;
    }
    if(d==0 && a[x][y+1]=='.') dfs(x,y+1,d,--k);
    else{
        k--;
        d=(d+1)%4;
    }
    if(d==1 && a[x+1][y]=='.') dfs(x+1,y,d,--k);
    else{
        k--;
        d=(d+1)%4;
    }
    }
    if(d==3){
    if(d==3 && a[x-1][y]=='.') dfs(x-1,y,d,--k);
    else{
        k--;
        d=(d+1)%4;
    }
    if(d==2 && a[x][y-1]=='.') dfs(x,y-1,d,--k);
    else{
        k--;
        d=(d+1)%4;
    }
    if(d==1 && a[x+1][y]=='.') dfs(x+1,y,d,--k);
    else{
        k--;
        d=(d+1)%4;
    }
    if(d==0 && a[x][y+1]=='.') dfs(x,y+1,d,--k);
    else{
        k--;
        d=(d+1)%4;
    }

    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
            memset(a,0,sizeof(a));
            memset(f,0,sizeof(f));
            flag=false;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int p=1;p<=n;p++){
            for(int q=1;q<=m;q++){
                cin>>a[p][q];
            }
        }
        dfs(x,y,d,k);
        cout<<sum<<endl;
        sum=0;
    }
    return 0;
}
