#include <cstdio>
#define rep(i,a,b) for(int i(a);i<(b);++i)
using namespace std;
int a[32]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88},b[16]={88,108,188,200,208,288,688};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(n<=14)
        {
            printf("%d\n",a[n]);
        }
        else
        {
            printf("%d",b[n%7]);
            rep(i,0,n/7-2) putchar('8');
            putchar('\n');
        }
    }
	return 0;
}
