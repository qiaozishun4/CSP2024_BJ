#include<iostream>
#include<string>
using namespace std;
int ans[1005];
int anss=1;
char a[1005][1005];
bool vis[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m,k,cnt;

void dfs(int x,int y,int d,int cs){
    vis[x][y]=true;
    if(cs==k){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]){
                    cnt++;
                    vis[i][j]=false;
                }
            }
        }
        ans[anss++]=cnt;
        cnt=0;
        return ;
    }
    int xxx=x+dx[d];
    int yyy=y+dy[d];
    if(xxx<1||xxx>n||yyy<1||yyy>m||a[xxx][yyy]=='x'){
        dfs(x,y,(d+1)%4,cs+1);
    }else{
        dfs(xxx,yyy,d,cs+1);
    }
}

void clea(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=0;
        }
    }
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int xx,yy,dd;
        cin>>n>>m>>k>>xx>>yy>>dd;
        string s;
        for(int i=1;i<=n;i++){
            cin>>s;
            for(int j=0;j<m;j++){
                a[i][j+1]=s[j];
            }
        }
        dfs(xx,yy,dd,0);
        clea();
    }
    for(int i=1;i<anss;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
