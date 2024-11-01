//PASS
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool flag[1111][1111];
char a[1111][1111];
void init(){
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            a[i][j+1]=s[j];
        }
        for(int j=1;j<=m;j++){
            flag[i][j]=0;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        init();
        while(k--){
            flag[x][y]=1;
            int tx=x+dx[d],ty=y+dy[d];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]=='.'){
                x=tx;
                y=ty;
            }
            else{
                d=(d+1)%4;
            }
        }
        flag[x][y]=1;
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(flag[i][j])ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}//diff explore1.out explore1.ans
