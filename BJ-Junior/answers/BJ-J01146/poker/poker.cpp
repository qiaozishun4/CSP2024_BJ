#include<iostream>
using namespace std;
const char d[]={"DAD2D3D4D5D6D7D8D9DTDJDQDKCAC2C3C4C5C6C7C8C9CTCJCQCKHAH2H3H4H5H6H7H8H9HTHJHQHKSAS2S3S4S5S6S7S8S9STSJSQSK"};
int n,ans=0;
bool cnt[53];
char c[2];
int main()
{
    //freopen("joker.in","w",stdin);
    //freopen("joker.out","r",stdout);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",c);
        for(int i=0;i<52;i++)
            if(c[0]==d[i*2]&&c[1]==d[i*2+1])
            {
                cnt[i]=true;
                break;
            }
    }
    for(int i=0;i<52;i++)ans+=(!cnt[i]);
    printf("%lld\n",ans);
    return 0;
}
//csp rp++!
//I love CCF
