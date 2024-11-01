#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn=2e5+5;

int t;
int n,k,qs;

bool f[11][maxn][7];

vector<int>v[maxn];
vector<int>s[maxn];
int l[maxn];

int s1[1005][2005];
int r,c;
int a;

bool hv[maxn];
bool ok[maxn];
int cnt;

struct nd{
    int i,v,r;
};

struct rc{
    int r,c;
}ask[maxn];

queue<nd>q;

bool cmp(rc a,rc b){
    if(a.r!=b.r)return a.r<b.r;
    return a.c<b.c;
}

void sv2(){
    memset(f,0,sizeof f);
    f[0][0][0]=1;
    for(int i=1;i<=n;i++){
        cin>>l[i];
        for(int j=1;j<=l[i];j++){
            int a;
            cin>>a;
            s[i].push_back(a);
        }
    }
    for(int i=1;i<=qs;i++)cin>>ask[i].r>>ask[i].c;
    q.push(nd{0,1,0});
    while(q.size()){
        nd u=q.front();
        q.pop();
        if(u.r>=6||f[u.i][u.v][u.r])continue;
        f[u.i][u.v][u.r]=1;
        for(int i=1;i<=n;i++){
            if(i==u.i)continue;
            for(int j=0;j<l[i];j++){
                if(s[i][j]!=u.v)continue;
                for(int x=j+1;x<=min(l[i]-1,j+k-1);x++)q.push(nd{i,s[i][x],u.r+1});
            }
        }
    }
    for(int i=1;i<=qs;i++){
        bool ans=0;
        for(int j=1;j<=n;j++)ans|=f[j][ask[i].c][ask[i].r];
        cout<<ans<<'\n';
    }
    for(int i=1;i<=n;i++)s[i].clear();
}

void sv1(){
    memset(hv,0,sizeof hv);
    memset(ok,0,sizeof ok);
    for(int i=1;i<=n;i++){
        cin>>l[i];
        for(int j=1;j<=l[i];j++){
            cin>>s1[i][j];
            hv[s1[i][j]]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=l[i];j++){
            if(s1[i][j]==1){
                for(int x=j+1;x<=min(j+k-1,l[i]);x++)ok[s1[i][x]]=1;
            }
        }
    }

    while(qs--){
        cin>>r>>c;
        cnt++;
        if(r==1)cout<<ok[c]<<'\n';
        else cout<<hv[c]<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>qs;
        if(n<=10)sv2();
        else sv1();
    }
    return 0;
}
