#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn=1e5+10;
int n,m;
int A[Maxn];
int c[Maxn];
int a[Maxn];
int K;
char ch[25][Maxn];
vector<int> test;
int work0()
{
    vector<int> now=test;
    int Round=1;
    while(now.size()!=1)
    {
        int Now=1;
        vector<int> nxt;
        for(int i=0;i<now.size();i+=2)
        {
            // i,i^1
            int qwq;
            if(ch[Round][Now]=='0') qwq=i;
            else qwq=i^1;
            //cout<<"Round "<<Round<<"; Now="<<Now<<";qwq="<<qwq<<endl;
            if(a[now[qwq]]>=Round)
                nxt.push_back(now[qwq]);
            else
                nxt.push_back(now[qwq^1]);
            Now++;
        }
        now=nxt;
        Round++;
    }
    return now[0];
}
void solve1()
{
    int T;
    scanf("%lld",&T);
    while(T--)
    {
        int x[4];
        scanf("%lld%lld%lld%lld",&x[0],&x[1],&x[2],&x[3]);
        for(int i=1;i<=n;i++)
        {
            a[i]=A[i]^x[i%4];
        }
        int now=1;
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            int now=1;
            test.clear();
            while(now<=c[i])
            {
                test.push_back(now);
                now++;
            }
            //cout<<"i="<<i<<",c[i]="<<c[i]<<endl;
            ans^=(i*work0());
        }
        printf("%lld\n",ans);
    }
}
int qpow(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
        {
            res=res*a;
        }
        a=a*a;
        b>>=1;
    }
    return res;
}
signed main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&A[i]);
    }
    bool flag=1;
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&c[i]);
        int q=log2(c[i]);
        int p=qpow(2,q);
        if(c[i]!=p) flag=0;
    }
    K=log2(n);
    while(qpow(2,K)<n) K++;
    for(int i=1;i<=K;i++)
    {
        for(int j=1;j<=qpow(2,K-i);j++)
        {
            cin>>ch[i][j];
        }
    }
    //cout<<"GOT THERE"<<endl;
    //return 0;
    if(flag)
    {
        solve1();
        return 0;
    }
    return 0;
}
