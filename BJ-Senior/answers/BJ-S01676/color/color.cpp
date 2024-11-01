#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[200005];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&t);
    int colr;
    int l;
    int ans;
    int maxans;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        if(n<=15)
        {
            colr=0;
            maxans=-1;
            for(colr=0;colr<=(1<<n)-1;colr++)
            {
                ans=0;
                for(int i=0;i<n;i++)
                {
                    l=i+1;
                    while(l<n)
                    {
                        if((colr>>l)%2==(colr>>i)%2)
                        {
                            if(a[n-i]==a[n-l]) ans+=a[n-i];
                            break;
                        }
                        l++;
                    }
                }
                maxans=max(maxans,ans);
                if(ans==31) cout<<'*'<<colr;
            }
            printf("%d\n",maxans);
        }
    }
    return 0;
}
