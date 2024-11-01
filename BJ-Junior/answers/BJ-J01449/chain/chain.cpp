#include<bits/stdc++.h>
using namespace std;

int t,n,k,q;
int a[1010][2010],l[1010];
int ch[110][200010];
bool dfs(int x,int c,int lp){
    if(x==0)return c==1;
    if(ch[x][c]!=-1)return ch[x][c];
    for(int i=1;i<=n;i++){
        if(i==lp)continue;
        for(int j=l[i],la=l[i]+k;j>0;j--){
            if(a[i][j]==c)la=j;
            if(la-j+1<=k&&la-j+1>1){
                if(dfs(x-1,a[i][j],i)){
                    ch[x][c]=1;
                    return 1;
                }
            }
        }
    }
    ch[x][c]=0;
    return 0;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                cin>>a[i][j];
            }
        }
        int r,c;
        while(q--){
            memset(ch,-1,sizeof(ch));
            cin>>r>>c;
            if(r==1){
                bool f=0;
                for(int i=1;i<=n;i++){
                    for(int j=1,la=-k;j<=l[i]&&!f;j++){
                        if(a[i][j]==1)la=j;
                        if(a[i][j]==c){
                            if(j-la+1<=k&&j-la+1>1){
                                f=1;
                                break;
                            }
                        }
                    }
                }
                cout<<f<<'\n';
            }
            else{
                cout<<dfs(r,c,0)<<'\n';
            }
        }
    }
    return 0;
}
