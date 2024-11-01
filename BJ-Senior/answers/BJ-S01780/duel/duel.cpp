#include <cstdio>
#include <algorithm>
#define N 100008
#define rep(i,a,b) for(register int i(a);i<(b);++i)
using namespace std;
int a[N];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,cur,cnt,lst(0),kill;
    scanf("%d",&n);
    rep(i,0,n)
    {
        scanf("%d",a+i);
    }
    sort(a,a+n);
    cur=a[0],cnt=1;
    rep(i,1,n)
    {
        if(a[i]==cur) ++cnt;
        else
        {
            //printf("%d %d\n",cur,cnt);
            kill=min(lst,cnt);
            lst-=kill;
            lst+=cnt;
            cur=a[i],cnt=1;
        }
    }
    kill=min(lst,cnt);
    lst-=kill;
    lst+=cnt;
    //printf("%d %d\n",cur,cnt);
    printf("%d",lst);
    return 0;
}
