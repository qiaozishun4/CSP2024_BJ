#include <bits/stdc++.h>
using namespace std;
#define ll long long
int read(){
    int x=0,f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c-'0');
    return x*f;
}
void read(int &x){
    int f=1; x=0;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c-'0');
    x*=f;
}
void write(int x){
    if(x<10){
        putchar(x+'0');
        return ;
    }
    write(x/10);
    putchar(x%10+'0');
}
const int N=2e5+5,M=105;
vector<int>g[N<<1];
vector<int>plc[N];
vector<int>ss[N];
int T,n,m,q,cnt;
bool dp[N<<1][M];
int ddl[N];
int ac[N],ar[N],R;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--){
        cin>>n>>m>>q;
        if(m==2e5){
        cnt=0;
        for(int i=1;i<=2e5;i++) g[i].clear();
        for(int i=1;i<=n;i++){
            ss[i].clear();
            int s;
            cin>>s;
            for(int j=1;j<=s;j++){
                int k;
                cin>>k;
                ss[i].push_back(k);
                ddl[cnt]=i;
            }
        }
        R=0;
        for(int i=1;i<=q;i++) cin>>ar[i]>>ac[i],R=max(R,ar[i]);
        int w=cnt;
        for(int i=1;i<=2e5;i++) g[w+i].clear();
        for(int i=1,t=1;i<=n;i++){
            for(int j=0;j<ss[i].size();j++,t++){
                for(int k=1;k<m&&j+k<ss[i].size();k++){
                    g[ss[i][j]].push_back(ss[i][j+k]);
                }
            }
        }
        for(int i=0;i<=R;i++){
            for(int j=1;j<=w+2e5;j++){
                dp[j][i]=0;
            }
        }
        dp[1][0]=1;
        for(int i=0;i<R;i++){
            for(int j=1;j<=200000;j++){
                if(!dp[j][i]) continue;
                for(int v:g[j]) dp[v][i+1]=1;
            }
        }
        for(int i=1;i<=q;i++) cout<<dp[ac[i]][ar[i]]<<"\n";
            continue;
        }
        cnt=0;
        for(int i=1;i<=2e5;i++) plc[i].clear();
        for(int i=1;i<=n;i++){
            ss[i].clear();
            int s;
            cin>>s;
            for(int j=1;j<=s;j++){
                int k;
                cin>>k;
                g[++cnt].clear();
                ss[i].push_back(k);
                plc[k].push_back(cnt);
                ddl[cnt]=i;
            }
        }
        R=0;
        for(int i=1;i<=q;i++) cin>>ar[i]>>ac[i],R=max(R,ar[i]);
        int w=cnt;
        for(int i=1;i<=2e5;i++) g[w+i].clear();
        for(int i=1,t=1;i<=n;i++){
            for(int j=0;j<ss[i].size();j++,t++){
                for(int k=1;k<m&&j+k<ss[i].size();k++){
                    for(int v:plc[ss[i][j+k]]){
                        if(ddl[v]!=i) g[t].push_back(v);
                    }
                    g[t].push_back(w+ss[i][j+k]);
                }
            }
        }
        for(int i=0;i<=R;i++){
            for(int j=1;j<=w+2e5;j++){
                dp[j][i]=0;
            }
        }
        for(int v:plc[1]) dp[v][0]=1;
        for(int i=0;i<R;i++){
            for(int j=1;j<=w;j++){
                if(!dp[j][i]) continue;
                for(int v:g[j]) dp[v][i+1]=1;
            }
        }
        for(int i=1;i<=q;i++) cout<<dp[ac[i]+w][ar[i]]<<"\n";
    }
    return 0;
}

