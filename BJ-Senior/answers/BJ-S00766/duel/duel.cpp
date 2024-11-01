#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int a[N],s[N];
struct Lis
{
    int a,id;
}l[N];
bool cmp(Lis x,Lis y){return x.a<y.a;}
inline int max(const int &x,const int &y){return x>=y?x:y;}
inline int min(const int &x,const int &y){return x<=y?x:y;}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&l[i].a);
        l[i].id=i;
    }
    sort(l+1,l+n+1,cmp);
    int kcur=0;
    for(int i=1;i<=n;i++)
    {
        if(i==1) ++kcur;
        else if(l[i].a!=l[i-1].a) ++kcur;
        a[l[i].id]=kcur;
    }
    int maxn=-1;
    for(int i=1;i<=n;i++)
    {
        maxn=max(maxn,a[i]);
        ++s[a[i]];
    }
    for(int i=2;i<=maxn;i++)
    {
        int notused=s[i];
        for(int j=1;j<i;j++)
        {
            if(notused==0) break;
            int killed=min(notused,s[j]);
            s[j]-=killed;
            notused-=killed;
        }
    }
    int cnt=0;
    for(int i=1;i<=maxn;i++) cnt+=s[i];
    printf("%d\n",cnt);
    return 0;
}