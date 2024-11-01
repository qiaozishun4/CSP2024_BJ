#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005],cnt[1000005];
bool color[100005];
struct node
{
    int l,r;
}couple[1000005];
signed main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;cin>>t;
    while(t--)
    {
        memset(couple,0,sizeof(couple));
        memset(cnt,0,sizeof(cnt));
        int n;cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            cnt[a[i]]++;
        }
        int ans=0,flag=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[i]==a[j]) couple[++flag].l=i,couple[flag].r=j,ans+=a[i];
            }
        }
        for(int i=1;i<=flag;i++)
        {
            for(int j=1;j<=flag;j++)
            {
                if(couple[j].l>couple[i].l&&couple[j].l<couple[i].r)
                {
                    if(couple[j].l=couple[j].r-1) continue;
                    if(couple[j].l=couple[i].r-1) continue;
                    ans-=a[couple[j].l];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
//n=2000,a[i]=2000
