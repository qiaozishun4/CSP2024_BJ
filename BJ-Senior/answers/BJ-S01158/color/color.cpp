#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,T;
int a[N];
int book[N];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int c[N];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int f = 0;
        memset(book,0,sizeof book);
        for(int i = 1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            if(!book[a[i]]) book[a[i]] = 1;
            else f = 1;
        }
        !f?printf("0\n"):printf("%d\n",c[T]+114514);
    }
    return 0;
}
