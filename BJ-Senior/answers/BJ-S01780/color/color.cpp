#include <cstdio>
#include <algorithm>
#define N 200008
#define rep(i,a,b) for(register int i(a);i<(b);++i)
using namespace std;
int v[N],lst[4],T,n,c,ans,tot;
inline void read(int &x)
{
    register int c;
    while((c=getchar())<'0'||c>'9');
    for(x=c^48;(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+(c^48));
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    read(T);
    while(T--)
    {
        read(n);
        rep(i,0,n)
        {
            read(v[i]);
        }
        ans=0;
        rep(i,0,(1<<n))
        {
            lst[0]=lst[1]=-1,tot=0;
            rep(j,0,n)
            {
                c=(i>>j)&1;
                if(lst[c]!=-1&&v[lst[c]]==v[j])
                {
                    tot+=v[j];
                }
                lst[c]=j;
            }
            ans=max(ans,tot);
        }
        printf("%d\n",ans);
    }
    return 0;
}
