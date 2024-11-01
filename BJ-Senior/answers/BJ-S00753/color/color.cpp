#include<bits/stdc++.h>
using namespace std;

int t,n;
int a[100010];
vector<int>v[1000010];

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            v[a[i]].push_back(i);
        }
        long long ans=0;
        for(int i=1;i<=1000000;i++)
        {
            if(v[i].size()>=2)
                ans+=(long long)(v[i].size()-1)*i;
            v[i].clear();
        }
        printf("%lld\n",ans);
    }
    return 0 ;
}