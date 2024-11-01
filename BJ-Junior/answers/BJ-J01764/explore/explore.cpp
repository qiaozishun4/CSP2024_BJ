#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,dx[5]={1,1,-1,-1},cnt,n,m;
char a[5010][5010];
bool mp[5010][5010];
bool check(int x,int y){
    if(x<=n&&x>=1&&y<=m&&y>=1){
        return true;
    }
    return false;
}
void f(int k,int x,int y,int d){
    if(k<=0){
        return ;
    }
    //cout<<x<<" "<<y<<" "<<d<<endl;
    if(d==0||d==2){
        if(a[x][y+dx[d]]!='x'&&check(x,y+dx[d])){
            //if(!mp[x][y+dx[d]]){
                mp[x][y+dx[d]]=1;
                //cnt++;
            //}
            f(k-1,x,y+dx[d],d);
        }
        else if(a[x][y+dx[d]]=='x'||!check(x,y+dx[d])){
            f(k-1,x,y,(d+1)%4);

        }
    }
    else if(d==1||d==3){
        if(a[x+dx[d]][y]!='x'&&check(x+dx[d],y)){
            //f(!mp[x+dx[d]][y]){
                mp[x+dx[d]][y]=1;
                //cnt++;
            //}
            f(k-1,x+dx[d],y,d);
        }
        else if(a[x+dx[d]][y]=='x'||!check(x+dx[d],y)){
            f(k-1,x,y,(d+1)%4);
        }
    }
}
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>t;
    while(t--){
        cnt=0;
        memset(mp,0,sizeof mp);
        int k,x,y,d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        mp[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        f(k,x,y,d);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mp[i][j]){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
