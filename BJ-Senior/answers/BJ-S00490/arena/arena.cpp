#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int n,m;
int base[N],a[N],c[N],x[5];
bool f[N];
string s[30];
int q[N];
int T;
int ans;
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        cin>>base[i];
    }
    for (int i=1;i<=m;++i)
    {
        cin>>q[i];
    }
    int K=ceil(log2(n));
    for (int i=1;i<=K;++i)
    {
        cin>>s[i];
    }
    cin>>T;
    cin>>x[0]>>x[1]>>x[2]>>x[3];
    for (int i=1;i<=n;++i)
    {
        a[i]=base[i]^(x[i%4]);
    }
    for (int i=1;i<=m;++i)
    {
        memset(f,0,sizeof(f));
        int round=log2(q[i]);
        for (int j=1;j<=round;++j)
        {
            for (int k=1;k<=(int)pow(2,round-j+1);k+=2)
            {
                if (s[j][k/2]=='0') //leizhu:k
                {
                    if (a[k]>=round)
                    {
                        c[k/2+1]=k;
                        f[k+1]=true;
                    }
                    else
                    {
                        c[k/2+1]=k+1;
                        f[k]=true;
                    }
                }
                if (s[j][k/2]=='1') //leizhu:k+1
                {
                    if (a[k+1]>=round)
                    {
                        c[k/2+1]=k+1;
                        f[k]=true;
                    }
                    else
                    {
                        c[k/2+1]=k;
                        f[k+1]=true;
                    }
                }
            }
            memset(a,0,sizeof(a));
            for (int k=1;k<=(int)pow(2,round-j);++k)
            {
                a[k]=c[k];
            }
            memset(c,0,sizeof(c));
        }
        for (int j=1;j<=q[i];++j)
        {
            if (!f[j])
            {
                ans=(ans^j);
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
