#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
struct node{
    int x,y,d,step,cnt;
};
int v[1001][1001];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
char G[1001][1001];
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(G,0,sizeof(G));
        memset(v,0,sizeof(v));
        int n,m,k,ans=0;
        cin>>n>>m>>k;
        // cout<<k<<endl;
        int x,y,d;
        cin>>x>>y>>d;
        bool xx=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>G[i][j];
                if(G[i][j]=='x') xx=1;
            }
        }
        if(k==1){
            if(G[x+dx[d]][y+dy[d]]=='.'&&x+dx[d]>=1&&x+dx[d]<=n&&y+dy[d]>=1&&y+dy[d]<=m) puts("2");
            else puts("1");
        }
        else if(!xx){
            int cnt=0;
            while(k>0){
                if(d==0){
                    while(y<=n&&k){
                        if(!v[x][y]) cnt++;
                        y++;
                        k--;
                    }
                    d++;
                    k--;
                    d%=4;
                }else if(d==1){
                    while(x<=m&&k){
                        if(!v[x][y]) cnt++;
                        x++;
                        k--;
                    }
                    d++;
                    d%=4;
                    k--;
                }else if(d==2){
                    while(y>=1&&k){
                        if(!v[x][y]) cnt++;
                        y--;
                        k--;
                    }
                    d++;
                    k--;
                    d%=4;
                }else if(d==3){
                    while(x>=1&&k){
                        if(!v[x][y]) cnt++;
                        x--;
                        k--;
                    }
                    d++;
                    d%=4;
                    k--;
                }
            }
            cout<<cnt<<endl;
        }
        else if(n==1){
            int cntl=0,cntr=0;
            for(int i=x;i<=n;i++){
                if(G[1][i]=='.') cntl++;
                else break;
            }
            for(int i=x;i>=1;i--){
                if(G[1][i]=='.') cntr++;
                else break;
            }
            bool big=0;
            if(cntl>=cntr){
                k-=4-abs(2-d);
                d=2;
            }else{
                k-=4-abs(0-d);
                d=0;
            }
            int ans=1;
            if(big){
                if(k>0){
                    if(k<cntr){
                        cout<<k<<endl;
                        continue;
                    }else{
                        ans+=cntr;
                        k-=cntr;
                    }
                }
                k-=2;
                if(k>0){
                   if(k<cntl){
                        cout<<k<<endl;
                        continue;
                    }else{
                        ans+=cntl;
                        k-=cntl;
                    } 
                }
            }else{
                if(k>0){
                    if(k<cntl){
                        cout<<k<<endl;
                        continue;
                    }else{
                        ans+=cntl;
                        k-=cntl;
                    }
                }
                k-=2;
                if(k>0){
                   if(k<cntr){
                        cout<<k<<endl;
                        continue;
                    }else{
                        ans+=cntr;
                        k-=cntr;
                    } 
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}