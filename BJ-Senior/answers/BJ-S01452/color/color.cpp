#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005];
bool color[100005];
bool exist_[1000005];
signed main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        if(n<=17)
        {
            int ans=0;
            memset(a,0,sizeof a);
            memset(color,0,sizeof color);
            for(int i=1;i<=n;i++)
                cin>>a[i];
            int maxx=pow(2,n)-1;
            for(int i=0;i<=maxx;i++)
            {
                for(int j=0;j<n;j++)
                {
                    int ls=pow(2,j);
                    if(i&ls)
                        color[j+1]=1;
                    else
                        color[j+1]=0;
                }
                int ret=0;
                for(int j=n;j>=1;j--)
                {
                    int k;
                    for(k=j-1;k>=1;k--)
                        if(color[j]==color[k])
                            break;
                    if(color[j]==color[k])
                        if(a[j]==a[k])
                            ret+=a[j];
                }
                ans=max(ans,ret);
            }
            cout<<ans<<endl;
        }
        else
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                cin>>a[i];
                if(exist_[a[i]])
                    ans=max(ans,a[i]);
                exist_[a[i]]=true;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
