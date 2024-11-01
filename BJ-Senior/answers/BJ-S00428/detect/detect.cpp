#include <fstream>
#include <cmath>
#include <cassert>
#include <vector>
using namespace std;
ifstream cin ("detect.in");
ofstream cout ("detect.out");
const int MAXN = 1e5+10,MAXM=1e6+10;
int p[MAXN];
int lst[MAXM],nxt[MAXM];
int d[MAXN],v[MAXN],a[MAXN];
int L[MAXN],R[MAXN];
bool tg[MAXN];
struct Solver
{
    vector <int> gz[MAXN];
    int n;
    void init (int n)
    {
        this->n=n;
        for (int i=1;i<=n;i++)
        {
            gz[i].clear();
        }
    }
    void add (int l,int r)
    {
        gz[l].emplace_back(r);
    }
    int solve (void)
    {
        int M = 1e9;
        int cnt = 0;
        for (int i=1;i<=n;i++)
        {
            for (auto t:gz[i])
            {
                M = min(M,t);
            }
            if (M==i)
            {
                cnt++;
                M = 1e9;
            }
        }
        return cnt;
    }
}S;
bool check (int st,int a,int v,int p,int V)
{
    // test if v>V, starts with pos=st,v0=v,a=a
    int dx = p-st;
    return v*v+2*a*dx > V*V;
}
int main ()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n,m,LE,V;
        cin>>n>>m>>LE>>V;
        for (int i=1;i<=n;i++)
        {
            tg[i]=0;
        }
        for (int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for (int i=1;i<=m;i++)
        {
            cin>>p[i];
            for (int j=p[i-1];j<p[i];j++)
            {
                lst[j]=i-1;
            }
            for (int j=p[i-1]+1;j<=p[i];j++)
            {
                nxt[j]=i;
            }
        }
        for (int j=p[m];j<=LE;j++)
        {
            lst[j]=m;
        }
        for (int i=1;i<=n;i++)
        {
            if (d[i]>p[m])
            {
                continue;
            }
            if (a[i]==0)
            {
                if (v[i]>V)
                {
                    L[i]=nxt[d[i]],R[i]=m;
                    tg[i]=1;
                }
            }
            else if (a[i]>0)
            {
                if (v[i]>V)
                {
                    L[i]=nxt[d[i]];
                    R[i]=m;
                    tg[i]=1;
                }
                else
                {
                    double D = (1.0*V*V-1.0*v[i]*v[i])/(2.0*a[i])+d[i];
                    if (D<=p[m])
                    {
                        int  t = nxt[int(ceil(D))];
                        if (D==p[t])
                        {
                            L[i]=t+1;
                            R[i]=m;
                        }
                        else
                        {
                            L[i]=t;
                            R[i]=m;
                        }
                        if (!check(d[i],a[i],v[i],p[L[i]],V))
                        {
                            L[i]++;
                        }
                        if(L[i]<=R[i])
                        {
                            tg[i]=1;
                        }
                    }
                }
            }
            else
            {
                if (v[i]>=V)
                {
                    L[i]=nxt[d[i]];
                    double D = (1.0*V*V-1.0*v[i]*v[i])/(2.0*a[i])+d[i];
                    if (D>LE)
                    {
                        R[i]=m;
                    }
                    else
                    {
                        R[i]=lst[int(floor(D))];
                        if (p[R[i]]==D)
                        {
                            R[i]--;
                        }
                    }
                    if (L[i]<=R[i])
                    {
                        tg[i]=1;
                    }
                }
            }
        }
        S.init(m);
        int cnt=0;
        for (int i=1;i<=n;i++)
        {
            if (tg[i])
            {
                // cerr<<i<<" "<<L[i]<<' '<<R[i]<<endl;
                S.add(L[i],R[i]);
                cnt++;
            }
        }
        cout<<cnt<<' '<<m-S.solve()<<'\n';
    }
}