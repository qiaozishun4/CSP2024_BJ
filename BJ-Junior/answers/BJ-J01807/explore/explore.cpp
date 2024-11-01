#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
char a[1010][1010];
bool f[1010][1010];
void go(){
    int xx=x,yy=y;
    if(d==0)yy++;
    if(d==1)xx++;
    if(d==2)yy--;
    if(d==3)xx--;
    if(xx<1||xx>n||yy<1||yy>m||a[xx][yy]=='x')d=(d+1)%4;
    else x=xx,y=yy;
    f[x][y]=true;
}
int cnt(){
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(f[i][j])sum++;
        }
    }
    return sum;
}
void solve(){
    cin>>n>>m>>k>>x>>y>>d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            f[i][j]=false;
        }
    }
    f[x][y]=true;
    while(k--)go();
    cout<<cnt()<<'\n';
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)solve();
    return 0;
}
