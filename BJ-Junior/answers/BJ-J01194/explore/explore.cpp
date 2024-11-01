#include<bits/stdc++.h>
using namespace std;
const int N=1005;
string s[N];
int n,m,k,t;
int x,y,d;
bool b[N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        memset(b,0,sizeof b);
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            cin>>s[i];
            s[i]=' '+s[i];
        }
        int ans=1;
        b[x][y]=1;
        //cout<<d<<" "<<x<<" "<<y<<endl;
        while(k--){
            if(d==0&&y+1<=m&&s[x][y+1]=='.'){
                y=y+1;
                if(!b[x][y]){
                    ans++;
                    b[x][y]=1;
                    //cout<<d<<" "<<x<<" "<<y<<endl;
                }
            }
            else if(d==1&&x+1<=n&&s[x+1][y]=='.'){
                x=x+1;
                if(!b[x][y]){
                    ans++;
                    b[x][y]=1;
                    //cout<<d<<" "<<x<<" "<<y<<endl;
                }
            }
            else if(d==2&&(y-1)>=1&&s[x][y-1]=='.'){
                y=y-1;
                if(!b[x][y]){
                    ans++;
                    b[x][y]=1;
                    //cout<<d<<" "<<x<<" "<<y<<endl;
                }
            }
            else if(d==3&&(x-1)>=1&&s[x-1][y]=='.'){
                x=x-1;
                if(!b[x][y]){
                    ans++;
                    b[x][y]=1;
                    //cout<<d<<" "<<x<<" "<<y<<endl;
                }
            }
            else d=(d+1)%4;
        }
        cout<<ans<<endl;
    }
    cout.flush();
    return 0;
}