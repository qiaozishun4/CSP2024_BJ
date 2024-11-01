#include <cstdio>
#define rep(i,a,b) for(int i(a);i<=(b);++i)
using namespace std;
bool f[10][20];
char s[8];
int n,ans;
inline int k1(char c)
{
    if(c=='D') return 1;
    if(c=='C') return 2;
    if(c=='H') return 3;
    return 4;
}
inline int k2(char c)
{
    if(c=='A') return 1;
    if(c=='T') return 10;
    if(c=='J') return 11;
    if(c=='Q') return 12;
    if(c=='K') return 13;
    return c^48;
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    rep(i,1,n)
    {
        scanf("%s",s);
        f[k1(s[0])][k2(s[1])]=true;
    }
    rep(i,1,4)
    {
        rep(j,1,13)
        {
            ans+=!f[i][j];
        }
    }
    printf("%d",ans);
	return 0;
}
