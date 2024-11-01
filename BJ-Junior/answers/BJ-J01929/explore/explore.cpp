#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int p[1005][1005];
bool v[1005][1005][4];
int nx[4]={0,1,0,-1};
int ny[4]={1,0,-1,0};
void dfs(int x,int y,int d){
    //cout<<"x:"<<x<<" y:"<<y<<" d:"<<d<<'\n';
    if(v[x][y][d]==true)    return;
    v[x][y][d]=true;
    if(k==0)    return;
    k--;
    int newx=nx[d]+x;
    int newy=ny[d]+y;
    //cout<<"newx:"<<newx<<" newy:"<<newy<<" d:"<<d<<"\n";
    if(newx<=0 || newy<=0 || newx>n || newy>m){
        //cout<<"outmap\n";
        dfs(x,y,(d+1)%4);
        return;
    }
    if(p[newx][newy]==true){
        //cout<<"thing\n";
        dfs(x,y,(d+1)%4);
        return;
    }
    //cout<<"ok\n";
    dfs(newx,newy,d);
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        int x,y,d,cnt=0;
        cin>>x>>y>>d;
        memset(v,0,sizeof(v));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                char c;cin>>c;
                if(c=='x')  p[i][j]=1;
                else    p[i][j]=0;
            }
        dfs(x,y,d);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(v[i][j][0]==true || v[i][j][1]==true || v[i][j][2]==true || v[i][j][3]==true){
                    cnt++;
                }
            }
        }
        cout<<cnt<<'\n';
    }

    return 0;
}
