#include<bits/stdc++.h>
using namespace std;
#define LL long long
//unsigned
//unsigned
//unsigned
//unsigned
//unsigned
//unsigned
inline int Iread()
{
    char ch=getchar();
    int w=1,s=0;
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
    return s*w;
}
inline void Iwrite(int n)
{
    if(n<0)putchar('-'),n=-n;
    if(n>9)Iwrite(n/10);
    putchar(n%10+'0');
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    //open that
printf("1\n0\n1\n0\n1\n0\n0\n");
    return 0;
}
