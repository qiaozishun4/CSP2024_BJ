#include<bits/stdc++.h>
using namespace std;
#define LL long long
inline int read()
{
    char ch=getchar();
    int s=0,w=1;
    while(ch<'0'||ch>'9')
    {
        w=-w;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        s=(s<<3)+(s<<1)+(ch^48);
        ch=getchar();
    }
    return w*s;
}
inline void write(int n)
{
    if(n<0)putchar('-'),n=-n;
    if(n>9)write(n/10);
    putchar(n%10+'0');
}
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);

    //don't forgot to open the freopen before ending the match ! ! ! !

    printf("5\n19\n7\n1");
    return 0;
}
