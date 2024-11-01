#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define lb lower_bound
#define ub upper_bound
using namespace std;
ll read(){
    ll k=0;char c=getchar();bool flag=1;
    while(!isdigit(c)){if(c=='-')flag=0;c=getchar();}
    while(isdigit(c)){k=(k<<1)+(k<<3)+(c^48);c=getchar();}
    if(flag)return k;else return -k;
}
char readc(){
    char c=getchar();
    while(!isgraph(c))c=getchar();
    return c;
}
string reads(){
    string s="";char c=getchar();
    while(!isgraph(c))c=getchar();
    while(isgraph(c)){s+=c;c=getchar();}
    return s;
}
const int N=2e5+10;
const int inf=-1;
int n,k,q,l[N],dp[15][N];//can the i-th round ends in j
vector<int>a[N];
signed main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
    int T=read();
    while(T--){
		memset(dp,0,sizeof dp);
        n=read(),k=read(),q=read();
        for(int i=1;i<=n;++i){
            l[i]=read();
            a[i].clear();
            a[i].pb(0);
            for(int j=1;j<=l[i];++j)a[i].pb((int)read());
        }
        dp[0][1]=inf;
        for(int i=1;i<=10;++i){
            for(int j=1;j<=n;++j){
                for(int K=1;K<l[j];++K){
                    if(dp[i-1][a[j][K]]!=j&&dp[i-1][a[j][K]]){
                        int tmp=min(l[j],K+k-1);
                        for(int L=K+1;L<=tmp;++L){
							if(!dp[i][a[j][L]]||dp[i][a[j][L]]==j)dp[i][a[j][L]]=j;
							else dp[i][a[j][L]]=inf;
						}
                    }
                }
            }
        }
        while(q--){
            int r=read(),c=read();
            if(dp[r][c])printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}
//by 2c_s in luogu
