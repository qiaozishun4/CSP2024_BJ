#include<bits/stdc++.h>
#define LL long long
#define CLR(a,x) memset(a,x,sizeof(a))
using namespace std;
const int N=1e5+5;
const int M=1e6+5;
const int I_INF=2e9+5;
int t,n,m,a[N],c[N],d[20][N],xxx[4],aa[N],b[N];
int getval(int x) {
    int val=1;
    while(val<x)val*=2;
    return val;
}
int getval2(int x) {
    int val=1,l=0;
    while(val<x)val*=2,l++;
    return l;
}
vector<int>nxt;
int calc(vector<int>v,int dep) {
    int len=v.size();
    //for(auto x:v)cerr<<x<<" ";
    //cerr<<'\n';
    if(len==1)return v[0];
    nxt.clear();
    for(int i=0,j=1;i<v.size();i+=2,j++) {
        if(d[dep][j]) {
            if(a[v[i+1]]>=dep)nxt.push_back(v[i+1]);
            else nxt.push_back(v[i]);
        } else {
            if(a[v[i]]>=dep)nxt.push_back(v[i]);
            else nxt.push_back(v[i+1]);
        }
    }
    return calc(nxt,dep+1);
}
vector<int>now;int vis[100];
bool vv[20];
void dfs(int dep,int nc,LL &res) {
    if(dep>nc) {
        int w=calc(now,1);
        if(vv[w])return;
        vv[w]=1;
        res+=w;
        return;
    }
    for(int i=0;i<=5;i++) {
        a[dep]=i;
        dfs(dep+1,nc,res);
    }
}

string s[40];
int main() {
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    scanf("%d%d",&n,&m);
    bool flg=1;
    for(int i=1;i<=n;i++)cin>>aa[i];
    for(int i=1;i<=m;i++) {
        cin>>c[i];
        if((c[i]&(c[i]-1))!=0)flg=0;
    }
    //sort(c+1,c+m+1);
    int K=getval2(n);
    for(int i=1;i<=K;i++) {
        cin>>s[i];
        for(int j=0;j<s[i].size();j++)
            d[i][j+1]=s[i][j]-'0';
    }
    cin>>t;
    while(t--) {
        for(int i=0;i<4;i++)scanf("%d",&xxx[i]);
        for(int i=1;i<=n;i++)a[i]=aa[i]^xxx[i%4];
        //for(int i=1;i<=n;i++)cerr<<a[i]<<" ";
        //puts("");
        //now.clear();
        //for(int i=1;i<=4;i++)now.push_back(i);
        //printf("%d\n",calc(now,1));

        LL ans=0;
        CLR(vis,0);
        if(flg) {
            for(int i=1;i<=m;i++) {
                now.clear();
                for(int j=1;j<=c[i];j++)now.push_back(j);
                ans^=1ll*i*calc(now,1);
            }
            printf("%lld\n",ans);
            continue;
        } else {
            for(int i=1;i<=m;i++) {
                LL res=0;
                int nc=getval(c[i]);
                now.clear();
                for(int j=1;j<=nc;j++)now.push_back(j);//,cerr<<j<<" ";
                //cerr<<'\n';
                for(int j=1;j<=n;j++)b[j]=a[j];
                for(int j=1;j<=n;j++)vv[j]=0;
                dfs(c[i]+1,nc,res);
                for(int j=1;j<=n;j++)a[j]=b[j];
                //cerr<<res<<'\n';
                ans^=1ll*i*res;
            }
            printf("%lld\n",ans);
        }

    }

    return 0;
}
