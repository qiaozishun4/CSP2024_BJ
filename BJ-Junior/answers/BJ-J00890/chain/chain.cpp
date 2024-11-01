#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i++)
#define pll pair<ll,ll>
#define mkp make_pair
using namespace std;
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
    {
        if(ch=='-')
        {
            f=-1;
        }
        ch=getchar();
    }
    while(isdigit(ch))
    {
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return x*f;
}
vector<ll> s[100005];
ll tt[200005];
vector<pll> g[2005];
bool ans[100005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ll _=read();
    while(_--)
    {
        ll n=read(),k=read(),q=read();
        rep(i,1,n)
        {
            s[i].clear();
        }
        memset(ans,0,sizeof(ans));
        ll LENT=0;
        rep(i,1,n)
        {
            ll len=read();
            rep(j,1,len)
            {
                ll x=read();
                s[i].push_back(x);
            }
        }
        while(q--){
            ll r=read(),c=read();
            bool flg=0;
            rep(i,1,n){
                ll len=s[i].size();
                rep(j,0,len-1){
                    rep(C,1,k){
                        ll to=j+k;
                        if(to<len){
                            if(s[i][j]==1&&s[i][to]==c){
                                flg=1;
                                break;
                            }
                        }else{
                            break;
                        }
                    }
                    if(flg){
                        break;
                    }
                }
                if(flg){
                    break;
                }
            }
            if(flg){
                printf("1\n");
            }else{
                printf("0\n");
            }
        }
    }
    return 0;
}
