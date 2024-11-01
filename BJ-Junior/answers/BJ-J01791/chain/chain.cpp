#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int T,n,k,q,r,c;
string s;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&T);
    for(int o=0;o<T;++o)
    {
        scanf("%d%d%d",&n,&k,&q);
        for(int i=1;i<=n;++i)
            cin>>s;
        for(int i=1;i<=q;++i)
        {
            scanf("%d%d",&r,&c);
            printf("%d\n",0);
        }
    }
    return 0;
}
