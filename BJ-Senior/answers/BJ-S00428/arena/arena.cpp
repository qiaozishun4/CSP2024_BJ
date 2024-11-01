#include<fstream>
#include <cassert>
#include <string>
using namespace std;
ifstream cin ("arena.in");
ofstream cout ("arena.out");
const int MAXN = 1e5+10;
int v[MAXN];
int f[4*MAXN],ww[4*MAXN];
int a[MAXN],c[MAXN];
string s[20];
void build (int x,int dep,int t)
{
    int ls=x*2,rs=x*2+1;
    if (dep>1)
    {
        build(ls,dep-1,t*2);
        build(rs,dep-1,t*2);
    }
    if (ww[ls]==-1 or ww[rs]==-1)
    {
        ww[x]=-1;
        if (ww[ls]!=-1)
        {
            if (s[dep][x-t]=='0')
            {
                f[x]=(v[ww[ls]]>=dep?(v[ww[ls]]<=dep):1);
            }
            else
            {
                f[x]=1;
            }
        }
        else
        {
            assert(ww[rs]==-1);
            f[x]=1;

        }
    }
    else
    {
        if (s[dep][x-t]=='0')
        {
            ww[x]=(v[ww[ls]]>=dep?ww[ls]:ww[rs]);
        }
        else
        {
            ww[x]=(v[ww[rs]]>=dep?ww[rs]:ww[ls]);
        }
        f[x]=(v[ww[x]]<=dep);
    }
    // cerr<<x<<' '<<ww[x]<<' '<<dep<<' '<<ww[ls]<<' '<<ww[rs]<<endl;
}
int main ()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=m;i++)
    {
        cin>>c[i];
    }
    int K;
    for (int i=0;i<=20;i++)
    {
        if((1<<i)>=n)
        {
            K=i;
            break;
        }
    }
    for (int i=1;i<=K;i++)
    {
        cin>>s[i];
    }
    int T;
    cin>>T;
    while (T--)
    {
        int X[4];
        cin>>X[0]>>X[1]>>X[2]>>X[3];
        for (int i=1;i<=n;i++)
        {
            a[i]^=X[i%4];
        }
        long long int res= 0;
        for (int i=1;i<=m;i++)
        {
            int K;
            for (int j=0;j<=20;j++)
            {
                if((1<<j)>=c[i])
                {
                    K=j;
                    break;
                }
            }
            int M = 1<<K;
            for (int j=1;j<=c[i];j++)
            {
                v[j]=a[j];
                ww[M-1+j]=j;
            }
            for (int j=c[i]+1;j<=M;j++)
            {
                v[j]=-1;
                ww[M-1+j]=-1;
            }
            build(1,K,1);
            long long int sum = 0;
            if (c[i]==(1<<K))
            {
                sum+=ww[1];
            }
            else
            {
                for (int j=1;j<=c[i];j++)
                {
                    int t=M+j-1;
                    bool flag=1;
                    while (t)
                    {
                        if (ww[t]!=-1)
                        {
                            flag&=(ww[t]==j);
                        }
                        else
                        {
                            assert(ww[t*2+1]==-1);
                            flag&=f[t*2+1];
                        }
                        t/=2;
                    }
                    if (flag)
                    {
                        // cerr<<j<<endl;
                        sum+=j;
                    }
                }
            }
            res^=(i*sum);
        }
        cout<<res<<'\n';
    }
}