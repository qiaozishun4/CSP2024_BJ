#include <cstdio>
#include <iostream>
using namespace std;
bool mymap[1010][1010];
bool check(int x,int y,int n,int m){
    return 1<=x&&x<=n&&1<=y&&y<=m;
}
void f(int &x,int &y,int &d,int n,int m,int &ans){
    if(d==0&&mymap[x][y+1]&&check(x,y+1,n,m))y+=1,ans++;
    else if(d==1&&mymap[x+1][y]&&check(x+1,y,n,m))x+=1,ans++;
    else if(d==2&&mymap[x][y-1]&&check(x,y-1,n,m))y-=1,ans++;
    else if(d==3&&mymap[x-1][y]&&check(x-1,y,n,m))x-=1,ans++;
    else d++;
    d%=4;
    //printf("%d %d %d\n",x,y,d);
}
void solve(){
    int n,m,k,x0,y0,d0;
    int ans=1;
    scanf("%d%d%d%d%d%d",&n,&m,&k,&x0,&y0,&d0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            if(c=='x')mymap[i][j]=0;
            else if(c=='.')mymap[i][j]=1;
        }
    }
    for(int i=0;i<k;i++){
        f(x0,y0,d0,n,m,ans);
    }
    printf("%d\n",ans);
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
