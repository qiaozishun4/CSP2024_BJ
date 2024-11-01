#include <cstdio>
#include <cstring>
#define rep(i,a,b) for(register int i(a);i<(b);++i)
#define add(u,v,r) (e[++cnt]={(v),(r),hd[u]},hd[u]=cnt)
#define repg(i,x) for(register int i(hd[x]);i;i=e[i].nxt)
#define N 200010
using namespace std;
struct Edge
{
    int to,rk,nxt;
}e[N<<1];
int hd[N],a[N],tot,tgt,cnt;
bool suc;
template<typename T>
inline void read(T &x)
{
    register int c;
    while((c=getchar())<'0'||c>'9');
    for(x=c^48;(c=getchar())>='0'&c<='9';x=(x<<3)+(x<<1)+(c^48));
}
void dfs(int x,int step,int lst)
{
    if(step==tot)
    {
        if(x==tgt)
        {
            suc=true;
            //printf("(%d) ",x);
        }
        return;
    }
    repg(i,x)
    {
        if(e[i].rk!=lst)
        {
            dfs(e[i].to,step+1,e[i].rk);
            if(suc)
            {
                //printf("(%d) ",x);
                return;
            }
        }
    }
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T,n,m,q,l;
    read(T);
    while(T--)
    {
        memset(hd,0,sizeof(hd)),cnt=0;
        read(n),read(m),read(q);
        rep(i,0,n)  // person index
        {
            read(l);
            rep(j,0,l)  // sequence S
            {
                read(a[j]);
            }
            rep(j,0,l-1)
            {
                for(int k(j+1);k<l&&k<j+m;++k)
                {
                    add(a[j],a[k],i);
                }
            }
        }
//        rep(i,0,10)
//        {
//            printf("%d : ",i);
//            repg(j,i)
//            {
//                printf("(%d,%d) ",e[j].to,e[j].rk);
//            }
//            putchar('\n');
//        }
        while(q--)
        {
            read(tot),read(tgt),suc=false;
            dfs(1,0,-1);
            putchar(suc?'1':'0');
            putchar('\n');
        }
    }
	return 0;
}
