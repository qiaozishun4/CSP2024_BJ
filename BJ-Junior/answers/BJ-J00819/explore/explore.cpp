#include <bits/stdc++.h>
using namespace std;
char zb[1001][1001];
bool usd[1001][1001];
int n,m,ans;
long long k;
int T;
int fx[4]={0,1,0,-1};
int fy[4]={1,0,-1,0};
string s;
void fd(int x,int y,int d){
    usd[x][y]=true;
    if(k==0){
        return ;
    }
    k--;
    if(zb[x+fx[d]][y+fy[d]]=='.'){
        fd(x+fx[d],y+fy[d],d);
    }
    else{
        fd(x,y,(d+1)%4);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T){
        cin>>n>>m>>k;
        T--;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            cin>>s;
            for(int j=1;j<=m;j++){
                zb[i][j]=s[j-1];
            }
        }
        fd(x,y,d);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(usd[i][j]){
                    ans++;
                    usd[x][y]=0;
                }
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
