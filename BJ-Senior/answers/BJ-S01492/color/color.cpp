#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5,maxk=32768;
int T,n,a[maxn],ans,anss;//0blue 1red
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    for(int o=0;o<T;++o)
    {
        anss=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        for(int i=0;i<32768;++i)
        {
            int xred=0,xblue=0;
            ans=0;
            for(int j=1;j<=n;++j)
            {
                if(i & (1<<(j-1)))
                {
                    //red
                    if(a[j]==xred)
                    {
                        ans+=a[j];
                    }
                    xred=a[j];
                }
                else
                {
                    //blue
                    if(a[j]==xblue)
                    {
                        ans+=a[j];
                    }
                    xblue=a[j];
                }
            }
            anss=max(anss,ans);
        }
        printf("%d\n",anss);
    }
    return 0;
}
