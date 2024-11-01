#include<bits/stdc++.h>
#define pb push_back
#define endl '\n'
#define nit int

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
inline int read()
{
    static int x,sgn,c;
    x=0,sgn=1,c=getchar();
    while ((c<48||c>57)&&c!='-') c=getchar();
    if (c=='-') sgn=-1,c=getchar();
    while (c>=48&&c<=57) x=x*10+c-48,c=getchar();
    return x*sgn;
}

const nit N=2e5+233;
int n,a[N],c[N];
ll Ans;
inline void dfs(int k)
{
    if (k>n)
    {
        int lr=0,lb=0;
        ll ans=0;
        for (int i=1;i<=n;i++)
        {
            if (c[i]==1)
            {
                if (a[i]==a[lr]) ans+=a[i];
                lr=i;
            }
            else
            {
                if (a[i]==a[lb]) ans+=a[i];
                lb=i;
            }
        }
        Ans=max(Ans,ans);
        return;
    }
    c[k]=1,dfs(k+1);
    c[k]=0,dfs(k+1);
}
inline void _main()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    Ans=0,dfs(1),cout<<Ans<<endl;
}

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    nit t;
    for (cin>>t;t--;) _main();

    return 0;
}
//orz to nzhtl1477
//rp++
