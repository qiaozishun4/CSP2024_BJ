#include <bits/stdc++.h>
using namespace std;

template<typename T>
T read(T &x)
{
    bool flag=0;
    x=0;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar())
        if(ch=='-') flag=1;
    for(;isdigit(ch);ch=getchar())
        x=(x<<1)+(x<<3)+(ch^48);
    return flag?x=-x:x;
}
const int MAXN=1e5+3;
int n,a[MAXN];

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    read(n);
    for(int i=1;i<=n;i++)
        read(a[i]);
    sort(a+1,a+n+1);
    int pos=1;
    for(int i=1;i<=n;i++)
    {
        while(a[pos]<=a[i]&&pos<=n) ++pos;
        if(pos>n)
        {
            printf("%d",n-i+1);
            return 0;
        }
        ++pos;
    }
    return 0;
}
